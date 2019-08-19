#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 공백을 포함하여 한 글자(char)인 경우에 문자열을 구분자로 분리
void SplitStringByDelim(
    const string& data,
    char delim,
    vector<string>& tokens);

// 공백을 여부를 결정하여 여러 글자(string)인 문자열을 구분자로 분리
void SplitStringByDelims(
    const string& data,
    string& delim,
    vector<string>& tokens,
    vector<char>& delims,
    bool isWhitespace = false);

int main()
{
    // [Split String 1]
    {
        string data = "A B,C D";

        vector<string> tokens1;
        SplitStringByDelim(data, ',', tokens1);

        printf("=> %s\n", data.c_str());

        for (string element1 : tokens1)
        {
            vector<string> tokens2;
            SplitStringByDelim(element1, ' ', tokens2);

            for (string element2 : tokens2)
            {
                printf("%s\n", element2.c_str());
            }
        }
    }

    printf("\n");

    // [Split String 2]
    {
        string data = "AB,CD;E.FG.";
        string delim = ".,;";

        vector<string> tokens;
        vector<char> delims;

        SplitStringByDelims(data, delim, tokens, delims, false);

        printf("=> %s, (size = %d)\n", data.c_str(), tokens.size());

        for (string element : tokens)
        {
            printf("%s\n", element.c_str());
        }
    }

    printf("\n");

    // [Split String 3]
    {
        string data = ";.;.;";
        string delim = ".,;";

        vector<string> tokens;
        vector<char> delims;

        SplitStringByDelims(data, delim, tokens, delims, true);

        printf("=> %s, (size = %d)\n", data.c_str(), tokens.size());

        for (string element : tokens)
        {
            printf("%s\n", element.c_str());
        }
    }

    return 0;
}

void SplitStringByDelim(
    const string& data,
    char delim,
    vector<string>& tokens)
{
    string temp = "";

    stringstream stream(data);
    string element;

    tokens.clear();

    while (getline(stream, element, delim))
    {
        tokens.push_back(element);
    }
}

void SplitStringByDelims(
    const string& data,
    string& delim,
    vector<string>& tokens,
    vector<char>& delims,
    bool isWhitespace)
{
    string text = "";

    tokens.clear();
    delims.clear();

    for (size_t i = 0; i < data.length(); i++)
    {
        bool isSeparated = false;

        for (int j = 0; j < delim.length(); j++)
        {
            if (data[i] == delim[j])
            {
                delims.push_back(delim[j]);
                isSeparated = true;
            }
        }

        if (isSeparated)
        {
            if (isWhitespace || !text.empty())
            {
                tokens.push_back(text);
            }

            text = "";
        }
        else
        {
            text += data[i];
        }
    }

    if (isWhitespace || !text.empty())
    {
        tokens.push_back(text);
    }
}

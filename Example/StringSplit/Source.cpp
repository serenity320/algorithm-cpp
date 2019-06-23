#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// 공백을 포함하여 한 글자(char)인 경우에 문자열을 구분자로 분리
void SplitStringByDelim(
    string str,
    char delim,
    vector<string>& tokens);

// 공백을 여부를 결정하여 여러 글자(string)인 문자열을 구분자로 분리
void SplitStringByDelims(
    string str,
    string delim,
    vector<string>& tokens,
    vector<char>& delims,
    bool isWhitespace = false);

int main()
{
    // [Split String 1]
    {
        string str1 = "A B,C D";

        vector<string> tokens1;
        SplitStringByDelim(str1, ',', tokens1);

        printf("=> %s\n", str1.c_str());

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
        string str2 = "AB,CD;E.FG.";

        vector<string> tokens;
        vector<char> delims;

        SplitStringByDelims(str2, ".,;", tokens, delims, false);

        printf("=> %s, (size = %d)\n", str2.c_str(), tokens.size());

        for (string element : tokens)
        {
            printf("%s\n", element.c_str());
        }
    }

    printf("\n");

    // [Split String 3]
    {
        string str3 = ";.;.;";

        vector<string> tokens;
        vector<char> delims;

        SplitStringByDelims(str3, ".,;", tokens, delims, true);

        printf("=> %s, (size = %d)\n", str3.c_str(), tokens.size());

        for (string element : tokens)
        {
            printf("%s\n", element.c_str());
        }
    }

    return 0;
}

void SplitStringByDelim(
    string str,
    char delim,
    vector<string>& tokens)
{
    string temp = "";

    stringstream stream(str);
    string element;

    tokens.clear();

    while (getline(stream, element, delim))
    {
        tokens.push_back(element);
    }
}

void SplitStringByDelims(
    string str,
    string delim,
    vector<string>& tokens,
    vector<char>& delims,
    bool isWhitespace)
{
    string text = "";

    tokens.clear();
    delims.clear();

    for (size_t i = 0; i < str.length(); i++)
    {
        bool isSeparated = false;

        for (int j = 0; j < delim.length(); j++)
        {
            if (str[i] == delim[j])
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
            text += str[i];
        }
    }

    if (isWhitespace || !text.empty())
    {
        tokens.push_back(text);
    }
}

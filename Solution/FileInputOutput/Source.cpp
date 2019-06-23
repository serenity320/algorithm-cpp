#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void InputFileNameNumber(string& fileName);

int solution(vector<int> &A);

int main()
{
    string inputFileName = "input";
    string outputFileName = "output";

    //InputFileNameNumber(inputFileName);

    inputFileName += ".txt";
    outputFileName += ".txt";

    FILE* pInFile = fopen(inputFileName.c_str(), "rt");
    //FILE* pOutFile = fopen(outputFileName.c_str(), "wt");

    vector<int> A;

    // [Input]
    {
        int N = 0;

        fscanf(pInFile, "%d", &N); // stdin

        for (int i = 0; i < N; i++)
        {
            int num = 0;

            fscanf(pInFile, "%d", &num); // stdin

            A.push_back(num);
        }
    }

    int result = solution(A);

    fprintf(stdin, "%d", result); // pOutFile

    fclose(pInFile);
    //fclose(pOutFile);

    return 0;
}

void InputFileNameNumber(string& fileName)
{
    int number = 0;

    // InputFile의 번호 입력
    scanf("%d", &number);

    fileName += std::to_string(number);
}

int solution(vector<int> &A)
{
    int result = 0;

    const int N = A.size();

    // Solution

    return result;
}

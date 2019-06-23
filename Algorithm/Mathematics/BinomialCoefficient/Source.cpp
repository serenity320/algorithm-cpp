#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// [이항 계수] 
// 조합(Combination)의 경우의 수
// nCr = (n-1)C(r-1) + (n-1)Cr
int BinomialCoefficient_Recursion(vector<vector<int>>& bino, int n, int r);
int BinomialCoefficient_Iteration(vector<vector<int>>& bino, int n, int r);

int main()
{
    int n = 5;
    int r = 3;

    printf("[이항 계수] - Recursion\n");
    {
        vector<vector<int>> bino(n + 1, vector<int>(n + 1, -1)); // -1로 초기화

        int result = BinomialCoefficient_Recursion(bino, n, r);
        printf("=> %dC%d = %d\n", n, r, result);
    }

    printf("\n");

    printf("[이항 계수] - Iteration\n");
    {
        vector<vector<int>> bino(n + 1, vector<int>(n + 1, 0)); // 0으로 초기화

        int result = BinomialCoefficient_Iteration(bino, n, r);
        printf("=> %dC%d = %d\n", n, r, result);
    }

    return 0;
}

int BinomialCoefficient_Recursion(vector<vector<int>>& bino, int n, int r)
{
    int result = 0;

    if (r == 0 || r == n) // 계산 종료
    {
        bino[n][r] = 1;
    }
    else if (bino[n][r] < 0) // -1인 경우에만 계산 (중복 계산 X)
    {
        int a = BinomialCoefficient_Recursion(bino, n - 1, r - 1); // (n-1)C(r-1)
        int b = BinomialCoefficient_Recursion(bino, n - 1, r); // (n-1)Cr

        bino[n][r] = a + b; // Memorization
    }

    result = bino[n][r];

    return result;
}

int BinomialCoefficient_Iteration(vector<vector<int>>& bino, int n, int r)
{
    int result = 0;

    for (int i = 0; i <= n; i++)
    {
        int num = std::min(i, r);

        for (int j = 0; j <= num; j++)
        {
            if (j == 0 || j == i)
            {
                bino[i][j] = 1;
            }
            else
            {
                int a = bino[i - 1][j - 1]; // (n-1)C(r-1)
                int b = bino[i - 1][j]; // (n-1)Cr

                bino[i][j] = a + b; // Memorization
            }
        }
    }

    result = bino[n][r];

    return result;
}

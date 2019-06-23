#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// [조합] 서로 다른 n개의 원소에서 r개를 선택 / 순서X / 중복X < nCr >
void Combination_Recursion(vector<int>& data, vector<int>& buffers, int n, int r, int start, int index);
void Combination_Iteration(vector<int>& data, int n, int r);

// [중복 조합] 서로 다른 n개의 원소에서 r개를 선택 / 순서X / 중복O < nHk = (n+r-1)Cr >
void CombinationWithRepetition_Recursion(vector<int>& data, vector<int>& buffers, int n, int r, int start, int index);

int main()
{
    vector<int> data = { 1, 2, 3, 4, 5 };

    int n = data.size(); // 5
    int r = 3;

    printf("[Combination] - Recursion\n");
    {
        vector<int> buffer(n, 0);

        Combination_Recursion(data, buffer, n, r, 0, 0);
    }

    printf("\n");

    printf("[Combination] - Iteration\n");
    {
        Combination_Iteration(data, n, r);
    }

    printf("\n");

    printf("[Combination with Repetition] - Recursion\n");
    {
        vector<int> buffer(n, 0);

        CombinationWithRepetition_Recursion(data, buffer, n, r, 0, 0);
    }

    return 0;
}

// http://www.algocoding.net/design/search/combination.html
void Combination_Recursion(vector<int>& data, vector<int>& buffers, int n, int r, int start, int index)
{
    if (r == index)
    {
        printf("{ ");
        for (int i = 0; i < r; i++)
        {
            printf("%d ", buffers[i]);
        }
        printf("}\n");
    }
    else
    {
        // i = start
        for (int i = start; i < n; i++)
        {
            buffers[index] = data[i];

            // start = i + 1
            Combination_Recursion(data, buffers, n, r, i + 1, index + 1);
        }
    }
}

// http://blog.daum.net/rhaoslikesan/331
void Combination_Iteration(vector<int>& data, int n, int r)
{
    vector<bool> flags(n, false);

    fill_n(flags.begin(), r, true);

    do
    {
        printf("{ ");
        for (int i = 0; i < n; i++)
        {
            if (flags[i])
            {
                printf("%d ", data[i]);
            }
        }
        printf("}\n");
    } while (std::prev_permutation(flags.begin(), flags.end()));
}

// http://www.algocoding.net/design/search/combination.html
void CombinationWithRepetition_Recursion(vector<int>& data, vector<int>& buffers, int n, int r, int start, int index)
{
    if (r == index)
    {
        printf("{ ");
        for (int i = 0; i < r; i++)
        {
            printf("%d ", buffers[i]);
        }
        printf("}\n");
    }
    else
    {
        // i = start
        for (int i = start; i < n; i++)
        {
            buffers[index] = data[i];

            // start = i
            CombinationWithRepetition_Recursion(data, buffers, n, r, i, index + 1);
        }
    }
}

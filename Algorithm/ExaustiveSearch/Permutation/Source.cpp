#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// [순열] 서로 다른 n개의 원소에서 r개를 선택 / 순서O / 중복X < nPr >
void Permutation_Recursion(vector<int>& data, vector<int>& buffers, vector<bool>& flags, int n, int r, int index);
void Permutation_Iteration(vector<int>& data, int n, int r);

// [중복 순열] 서로 다른 n개의 원소에서 r개를 선택 / 순서O / 중복O < n^r >
void PermutationWithRepetition_Recursion(vector<int>& data, vector<int>& buffers, int n, int r, int index);

int main()
{
    vector<int> data = { 1, 2, 3, 4, 5 };

    int n = data.size(); // 5
    int r = 2;

    printf("[Permutation] - Recursion\n");
    {
        vector<int> buffers(n, 0);
        vector<bool> flags(n, false);

        Permutation_Recursion(data, buffers, flags, n, r, 0);
    }

    printf("\n");

    printf("[Permutation] - Iteration\n");
    {
        Permutation_Iteration(data, n, r);
    }

    printf("\n");

    printf("[Permutation With Repetition] - Recursion\n");
    {
        vector<int> buffers(n, 0);

        PermutationWithRepetition_Recursion(data, buffers, n, r, 0);
    }

    return 0;
}

// http://www.algocoding.net/design/search/permutation.html
void Permutation_Recursion(vector<int>& data, vector<int>& buffers, vector<bool>& flags, int n, int r, int index)
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
        for (int i = 0; i < n; i++)
        {
            if (!flags[i])
            {
                flags[i] = true;
                buffers[index] = data[i];

                Permutation_Recursion(data, buffers, flags, n, r, index + 1);

                flags[i] = false;
            }
        }
    }
}

// http://blog.daum.net/rhaoslikesan/331
void Permutation_Iteration(vector<int>& data, int n, int r)
{
    vector<int> copied(data);

    sort(copied.begin(), copied.end());

    do
    {
        printf("{ ");
        for (int i = 0; i < r; i++)
        {
            printf("%d ", copied[i]);
        }
        printf("}\n");

        reverse(copied.begin() + r, copied.end());
    } while (std::next_permutation(copied.begin(), copied.end()));
}

// http://www.algocoding.net/design/search/combination.html
void PermutationWithRepetition_Recursion(vector<int>& data, vector<int>& buffers, int n, int r, int index)
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
        // i = 0
        for (int i = 0; i < n; i++)
        {
            buffers[index] = data[i];

            PermutationWithRepetition_Recursion(data, buffers, n, r, index + 1);
        }
    }
}

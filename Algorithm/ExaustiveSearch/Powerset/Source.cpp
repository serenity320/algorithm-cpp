#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void Powerset_Recursion(vector<int>& data, vector<int>& flags, int n, int index);
void Powerset_Iteration(vector<int>& data);
void Powerset_Permutation(vector<int>& data);

int main()
{
    vector<int> data = { 1, 2, 3, 4, 5 };

    printf("[Powerset] - Recursion\n");
    {
        vector<int> flags(data.size(), 0);

        Powerset_Recursion(data, flags, data.size(), 0);
    }

    printf("\n");

    printf("[Powerset] - Iteration\n");
    {
        Powerset_Iteration(data);
    }

    printf("\n");

    printf("[Powerset] - Permutation\n");
    {
        Powerset_Permutation(data);
    }

    return 0;
}

// http://swlock.blogspot.kr/2016/03/power-set.html
void Powerset_Recursion(vector<int>& data, vector<int>& flags, int n, int index)
{
    if (n == index) // 단말 노드
    {
        printf("{ ");
        for (int i = 0; i < n; i++)
        {
            if (flags[i] == 1)
            {
                printf("%d ", data[i]);
            }
        }
        printf("}\n");
    }
    else
    {
        // Left
        flags[index] = 1; // 선택 O
        Powerset_Recursion(data, flags, n, index + 1);

        // Right
        flags[index] = 0; // 선택 X
        Powerset_Recursion(data, flags, n, index + 1);
    }
}

//http://baboc.tistory.com/238
void Powerset_Iteration(vector<int>& data)
{
    int max = 1 << data.size();

    for (int b = 0; b < max; b++)
    {
        printf("{ ");
        for (size_t i = 0; i < data.size(); i++)
        {
            if (b & (1 << i)) // Bit Mask
            {
                printf("%d ", data[i]);
            }
        }
        printf("}\n");
    }
}

void Powerset_Permutation(vector<int>& data)
{
    for (size_t i = 0; i <= data.size(); i++)
    {
        vector<bool> flags(data.size(), false);

        fill_n(flags.begin(), i, true);

        do
        {
            printf("{ ");
            for (size_t i = 0; i < data.size(); i++)
            {
                if (flags[i])
                {
                    printf("%d ", data[i]);
                }
            }
            printf("}\n");
        } while (prev_permutation(flags.begin(), flags.end()));
    }
}

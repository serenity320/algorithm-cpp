#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void Subset_Recursion(vector<int>& data, vector<bool>& flags, int size, int sum, int num, int index);
void Subset_Iteration(vector<int>& data, int size, int sum);
void Subset_Permutation(vector<int>& data, int size, int sum);

int main()
{
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int size = data.size();
    int sum = 11; // 원소의 합이 11인 부분집합

    printf("[Subset] - Recursion\n");
    {
        vector<bool> flags(data.size(), false);

        Subset_Recursion(data, flags, size, sum, 0, 0);
    }

    printf("\n");

    printf("[Subset] - Iteration\n");
    {
        Subset_Iteration(data, size, sum);
    }

    printf("\n");

    printf("[Subset] - Permutation\n");
    {
        Subset_Permutation(data, size, sum);
    }

    return 0;
}

void Subset_Recursion(vector<int>& data, vector<bool>& flags, int size, int sum, int num, int index)
{
    if (size == index || sum <= num)
    {
        // Subset
        if (sum == num)
        {
            printf("{ ");
            for (int i = 0; i < size; i++)
            {
                if (flags[i])
                {
                    printf("%d ", data[i]);
                }
            }
            printf("}\n");
        }
    }
    else
    {
        // Left
        flags[index] = true; // 선택 O
        Subset_Recursion(data, flags, size, sum, num + data[index], index + 1);

        // Right
        flags[index] = false; // 선택 X
        Subset_Recursion(data, flags, size, sum, num, index + 1);
    }
}

void Subset_Iteration(vector<int>& data, int size, int sum)
{
    int max = 1 << size;

    for (int b = 0; b < max; b++)
    {
        vector<int> result;
        int num = 0;

        // Powerset
        for (int i = 0; i < size; i++)
        {
            if (b & (1 << i)) // Bit Mask
            {
                num += data[i];
                result.push_back(data[i]);
            }
        }

        // Subset
        if (sum == num)
        {
            printf("{ ");
            for (int element : result)
            {
                printf("%d ", element);
            }
            printf("}\n");
        }
    }
}

void Subset_Permutation(vector<int>& data, int size, int sum)
{
    for (int i = 0; i <= size; i++)
    {
        vector<bool> flags(size, false);

        fill_n(flags.begin(), i, true);

        do
        {
            vector<int> result;
            int num = 0;

            // Powerset
            for (int i = 0; i < size; i++)
            {
                if (flags[i])
                {
                    num += data[i];
                    result.push_back(data[i]);
                }
            }

            // Subset
            if (sum == num)
            {
                printf("{ ");
                for (int element : result)
                {
                    printf("%d ", element);
                }
                printf("}\n");
            }
        } while (prev_permutation(flags.begin(), flags.end()));
    }
}

#include <cstdio>
#include <cstdint>

#define MAX 0x7FFFFFFF
#define SIZE 1000

int main()
{
    FILE* pFile;
    int64_t input[SIZE] = { 0 };
    int result = 0;

    pFile = fopen("input.txt", "r");

    // Input
    for (int i = 0; i < SIZE; i++)
    {
        fscanf(pFile, "%llu", &input[i]); // -30억 <= X <= 30억
    }

    // Algorithm
    for (int i = 0; i < SIZE; i++)
    {
        int64_t mod = 0;

        mod = input[i] % MAX; // input이 MAX보다 클 경우
        mod = (result + mod) % MAX;
        result = static_cast<int>(mod);

        // SUM = 73218445
        // SUM of MOD = 10073218450
    }

    // Output
    printf("%d\n", result);

    fclose(pFile);

    return 0;
}

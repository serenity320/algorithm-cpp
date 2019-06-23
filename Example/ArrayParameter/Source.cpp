#include <cstdio>

#define MAX 15

void FuntionOfArray(int data[][MAX]);
void FunctionOfPorinter(int (*data)[MAX]);

int main()
{
    int data[MAX][MAX];

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            data[i][j] = i * MAX + j;
        }
    }

    FuntionOfArray(data);
    FunctionOfPorinter(data);

    return 0;
}

void FuntionOfArray(int data[][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", data[i][j]);
        }

        printf("\n");
    }
}

void FunctionOfPorinter(int (*data)[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", data[i][j]);
        }

        printf("\n");
    }
}

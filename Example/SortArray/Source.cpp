#include <cstdio>
#include <cstdlib>

int Compare(const void *args1, const void *args2);

int main()
{
    int data[6] = { 50, 20, 60, 40, 10, 30 };
    int size = 6;

    qsort(data, size, sizeof(int), Compare); // O(NlogN)

    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");

    return 0;
}

int Compare(const void *args1, const void *args2)
{
    int a = *(int*)args1;
    int b = *(int*)args2;

    return a - b; // ASC
}

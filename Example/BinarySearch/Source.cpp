#include <cstdio>
#include <cstdlib>

int Compare(const void *args1, const void *args2);

int main()
{
    int data[6] = { 50, 20, 60, 40, 10, 30 };
    int length = 6;

    int key = 30;

    qsort(data, length, sizeof(int), Compare); // O(NlogN)
    int *element = (int*)bsearch(&key, data, length, sizeof(int), Compare); // O(logN)   

    if (element != nullptr)
    {
        printf("%d is in the array.", *element);
    }
    else
    {
        printf("%d is not in the array.", *element);
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

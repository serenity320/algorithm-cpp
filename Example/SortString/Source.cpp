#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LENGTH 256

int main()
{
    char data[4][MAX_LENGTH] = { "some", "example", "strings", "here" };
    int size = 4;

    // O(NlogN)
    qsort(data, size, MAX_LENGTH, (int(*)(const void*, const void*))strcmp);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", data[i]);
    }

    return 0;
}

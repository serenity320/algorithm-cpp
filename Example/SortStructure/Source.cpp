#include <cstdio>
#include <cstdlib>

struct Position
{
    int x;
    int y;
};

int Compare(const void* args1, const void* args2);

int main()
{
    Position position[6] = {
        {50, 20},
        {20, 60},
        {60, 40},
        {40, 10},
        {10, 30},
        {30, 50}
    };
    int length = 6;

    qsort(position, length, sizeof(Position), Compare); // O(NlogN)

    for (int i = 0; i < length; i++)
    {
        printf("%d, %d\n", position[i].x, position[i].y);
    }

    return 0;
}

int Compare(const void* args1, const void* args2)
{
    int a = ((Position*)args1)->x;
    int b = ((Position*)args2)->x;

    return a - b; // ABS
}

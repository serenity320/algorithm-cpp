#include <cstdio>

#define HEIGHT 5
#define WIDTH 5

//#define DIRECTION 4
#define DIRECTION 8

int main()
{
    //const int directionY[DIRECTION] = { -1, 0, 0, 1 };
    //const int directionX[DIRECTION] = { 0, -1, 1, 0 };
    const int directionY[DIRECTION] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    const int directionX[DIRECTION] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    int result[HEIGHT][WIDTH] = { 0 };
    int map[HEIGHT][WIDTH] = {
        { 0, 4, 3, 3, 0 },
        { 1, 4, 0, 3, 8 },
        { 4, 7, 7, 3, 0 },
        { 4, 0, 5, 9, 9 },
        { 4, 2, 0, 6, 9 }
    };

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int sum = 0;

            for (int r = 0; r < DIRECTION; r++)
            {
                if ((i + directionY[r] >= 0 && i + directionY[r] < HEIGHT) &&
                    (j + directionX[r] >= 0 && j + directionX[r] < WIDTH))
                {
                    int y = i + directionY[r];
                    int x = j + directionX[r];

                    sum += map[y][x];
                }
            }

            result[i][j] = sum;
        }
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%3d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

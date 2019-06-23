#include <cstdio>

#define WIDTH 5
#define HEIGHT 5

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

int main()
{
    int snail[HEIGHT][WIDTH] = { 0 };
    int x = 0;
    int y = 0;

    Direction direction = RIGHT;
    int last = WIDTH * HEIGHT;
    int count = 0;

    while (count < last)
    {
        snail[y][x] = ++count;

        switch (direction)
        {
            case LEFT:
                if (x - 1 < 0 || snail[y][x - 1] != 0)
                {
                    direction = UP;
                }
                break;

            case RIGHT:
                if (x + 1 >= WIDTH || snail[y][x + 1] != 0)
                {
                    direction = DOWN;
                }
                break;

            case UP:
                if (y - 1 < 0 || snail[y - 1][x] != 0)
                {
                    direction = RIGHT;
                }
                break;

            case DOWN:
                if (y + 1 >= HEIGHT || snail[y + 1][x] != 0)
                {
                    direction = LEFT;
                }
                break;
        }

        switch (direction)
        {
            case LEFT:
                x--;
                break;

            case RIGHT:
                x++;
                break;

            case UP:
                y--;
                break;

            case DOWN:
                y++;
                break;
        }
    }

    for (int i = 0; i < HEIGHT; i++)
    {

        for (int j = 0; j < WIDTH; j++)
        {
            printf("%3d", snail[i][j]);
        }

        printf("\n");
    }

    return 0;
}

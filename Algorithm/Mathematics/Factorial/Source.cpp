#include <cstdio>

int Factorial(int n);

int main()
{
    int n = 10;

    int result = Factorial(n);
    printf("=> Factorial(%d) = %d\n", n, result);

    return 0;
}

int Factorial(int n)
{
    int result = 1;

    int num = n;

    while (num > 0)
    {
        result *= num;
        num--;
    }

    return result;
}

#include <cstdio>

double Power_Recursion(double base, int exp); // O(logN)
double Power_Iteration(double base, int exp); // O(logN)

int main()
{
    int base = 2;
    int exp = 10;

    printf("[°Åµì Á¦°ö] - Recursion\n");
    {
        double result = Power_Recursion(base, exp);

        printf("=> %d^%d = %.2lf\n", base, exp, result);
    }

    printf("\n");

    printf("[°Åµì Á¦°ö] - Iteration\n");
    {
        double result = Power_Iteration(base, exp);

        printf("=> %d^%d = %.2lf\n", base, exp, result);
    }

    return 0;
}

double Power_Recursion(double base, int exp) // O(logN)
{
    double result = 1.0;

    if (exp > 0)
    {
        double num = 1.0;

        if (exp % 2 == 1)
        {
            num *= base;
        }

        result = num * Power_Recursion(base * base, exp / 2);
    }

    return result;
}

double Power_Iteration(double base, int exp) // O(logN)
{
    double result = 1.0;

    while (exp)
    {
        if (exp % 2)
        {
            result *= base;
        }

        base *= base;
        exp /= 2;
    }

    return result;
}

#include <cstdio>
#include <vector>

using namespace std;

uint64_t Fibonacci(int n);
vector<uint64_t> FibonacciSequence(int n);
vector<bool> IsFibonacci(uint64_t n); // Fibo(x) : 0 ~ n

int main()
{
    int n = 15;

    printf("[피보나치 수]\n");
    {
        uint64_t fibo = Fibonacci(n);

        printf("F(%d) = %lld\n", n, fibo);
    }

    printf("\n");

    printf("[피보나치 수열]\n");
    {
        vector<uint64_t> fibo = FibonacciSequence(n);

        for (int i = 0; i <= n; i++)
        {
            printf("F(%d) = %lld\n", i, fibo[i]);
        }
    }

    printf("\n");

    printf("[피보나치 확인]\n");
    {
        uint64_t limit = 100;
        int number = 55; // O

        vector<bool> isFibo = IsFibonacci(limit);
        char sign = isFibo[number] ? 'O' : 'X';

        printf("%d is fibancci number : %c\n", number, sign);
    }

    return 0;
}

uint64_t Fibonacci(int n)
{
    uint64_t result = 0;
    
    if (n > 0)
    {
        uint64_t a = 0; // F(0)
        uint64_t b = 1; // F(1)

        for (int i = 2; i <= n; i++)
        {
            uint64_t c = a + b;

            // Next
            a = b;
            b = c;
        }

        result = b;
    }

    return result;
}

vector<uint64_t> FibonacciSequence(int n)
{
    vector<uint64_t> result(n + 1, 0);

    result[0] = 0; // F(0)

    if (n > 1)
    {
        result[1] = 1; // F(1)

        for (size_t i = 2; i <= n; i++)
        {
            result[i] = result[i - 1] + result[i - 2];
        }
    }

    return result;
}

vector<bool> IsFibonacci(uint64_t n)
{
    // Fibo(x)가 0 ~ n까지인 Fibonacci
    vector<bool> result(n + 1, false);

    uint64_t a = 0; // F(0)
    result[a] = true;

    if (n > 0)
    {
        uint64_t b = 1; // F(1)
        result[b] = true;

        while (b < n)
        {
            uint64_t c = a + b;

            if (c <= n)
            {
                result[c] = true;
            }

            // Next
            a = b;
            b = c;
        }
    }


    return result;
}
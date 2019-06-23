#include <cstdio>
#include <vector>

using namespace std;

uint64_t Fibonacci(int n);
vector<uint64_t> FibonacciSequence(int n);

int main()
{
    int n = 0;

    printf("[피보나치]\n");
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

    return 0;
}

uint64_t Fibonacci(int n)
{
    uint64_t result = 0;

    uint64_t a = 0; // F(0)
    uint64_t b = 1; // F(1)
    uint64_t c = 0;

    if (n > 0)
    {
        for (int i = 2; i <= n; i++)
        {
            c = a + b;

            // next
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
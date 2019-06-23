#include <cstdio>
#include <vector>

using namespace std;

// n의 약수 (나누어지는 수)
int CountingDivisors(int n);
vector<int> Divisors(int n);

// 1 ~ n의 약수 (나누어지는 수) 리스트
// 에라토스테네스의 체(Sieve Of Eratosthenes) 활용
vector<vector<int>> DivisorsList(int n);

int main()
{
    int n = 100;

    printf("[Counting Divisors] : %d\n", n);
    {
        int result = CountingDivisors(n);

        printf("%d", result);
    }

    printf("\n\n");

    printf("[Divisors] : %d\n", n);
    {
        vector<int> result = Divisors(n);

        for (int element : result)
        {
            printf("%d ", element);
        }
    }

    printf("\n\n");

    printf("[Divisors List] : %d\n", n);
    {
        vector<vector<int>> divisorsList = DivisorsList(n);

        for (size_t i = 2; i < divisorsList.size(); i++)
        {
            printf("[%d] ", i);

            for (int element : divisorsList[i])
            {
                printf("%d ", element);
            }

            printf("\n", i);
        }
    }

    return 0;
}

vector<int> Divisors(int n)
{
    vector<int> result; // Inorderd
    //set<int> result; // Order

    int i = 0;

    // Time Complexity : O(sqrt(N))
    // Space Complexity : O(1)
    for (i = 1; i < std::sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int a = n / i;
            int b = n;

            // A, B는 n의 약수(Divisor)
            // A * B = n

            result.push_back(a);
            result.push_back(b);
        }
    }

    if (i * i == n)
    {
        // i는 n의 약수(Divisor)
        // i * i = n

        result.push_back(i);
    }

    return result;
}

int CountingDivisors(int n)
{
    int result = 0;

    int i = 0;

    // Time Complexity : O(sqrt(N))
    // Space Complexity : O(1)
    for (i = 1; i < std::sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // A = n / i
            // B = n

            // A, B는 n의 약수(Divisor)
            // A * B = n

            result += 2; // A, B -> 2개
        }
    }

    if (i * i == n)
    {
        // i는 n의 약수(Divisor)
        // i * i = n

        result++; // 1개
    }

    return result;
}

vector<vector<int>> DivisorsList(int n)
{
    vector<vector<int>> result(n + 1); // Inorderd
    //vector<set<int>> result(n + 1); // Orderd

    for (int i = 1; i < std::sqrt(n); i++)
    {
        int j = i * i;

        while (j <= n)
        {
            result[j].push_back(i);

            if (j != i * i)
            {
                result[j].push_back(j / i);
            }

            j += i;
        }
    }

    return result;
}

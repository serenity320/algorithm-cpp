#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

// n을 나눌 수 있는 가장 작은 소수(Prime Number)
// 에라토스테네스의 체(Sieve Of Eratosthenes) 활용
vector<int> SmallestFactors(int n);

// 인수분해(Factorization) : 소수(Prime Number)들의 곱
multiset<int> Factorization(vector<int>& factors, int n);

int main()
{
    int n = 20;

    vector<int> factors = SmallestFactors(n);

    printf("[Smallest Factors] : %d\n", n);
    {
        for (int element : factors)
        {
            printf("%d ", element);
        }
    }

    printf("\n\n");

    printf("[Factorization] : %d\n", n);
    {
        multiset<int> result = Factorization(factors, n);

        for (int element : result)
        {
            printf("%d ", element);
        }
    }

    return 0;
}

vector<int> SmallestFactors(int n)
{
    vector<int> result(n + 1, 0);

    // Time Complexity : O(Nlog(log(N)))
    // Space Complexity : O(N)
    for (int i = 2; i < std::sqrt(n); i++)
    {
        if (result[i] == 0)
        {
            int j = i * i;

            while (j <= n)
            {
                if (result[j] == 0)
                {
                    // i : Smallest Prime Number
                    result[j] = i;
                }
                
                j += i;
            }
        }
    }

    // result(index >= 2)의 원소가 0이면 소수(Prime Number)

    return result;
}

multiset<int> Factorization(vector<int>& factors, int n)
{
    // Order : multiset<int>
    // Inorder : vector<int>
    multiset<int> result;

    int number = n;

    // Time Complexity : O(logN)
    // Space Complexity : O(N)
    while (factors[number] > 0)
    {
        result.insert(factors[number]);

        number /= factors[number];
    }

    result.insert(number);

    return result;
}

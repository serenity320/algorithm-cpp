#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void InfiniteCoin(); // 동전의 개수 무한
void FiniteCoin(); // 동전의 개수 유한(개수 입력)

// [동전 교환] 동전의 개수(무한)
int InfiniteCoins_NumberOfCases(vector<int>& coins, int k);
int InfiniteCoins_NumberOfCoins(vector<int>& coins, int k);
int InfiniteCoins_NumberOfCoins_Greedy(vector<int>& coins, int k);

// [동전 교환] 동전의 개수(유한)
int FiniteCoin_NumberOfCases(vector<pair<int, int>>& coins, int k);
int FiniteCoin_NumberOfCoins(vector<pair<int, int>>& coins, int k);

int main()
{
    // 동전의 개수가 무한한 경우
    InfiniteCoin();

    // 공전의 개수가 주어진 경우
    //FiniteCoin();

    return 0;
}

void InfiniteCoin()
{
    int n = 0; // 동전 종류의 개수
    int k = 0; // 지폐의 금액
    vector<int> coins; // 동전 종류

    // [input1.txt]
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        int coin = 0;

        scanf("%d", &coin);

        coins.push_back(coin);
    }

    //int cases = InfiniteCoins_NumberOfCoins_Iteration(coins, k);
    int numOfCases = InfiniteCoins_NumberOfCases(coins, k);
    int numOfCoins = InfiniteCoins_NumberOfCoins(coins, k);

    printf("[동전 교환] - 동전의 개수 무한\n");
    printf("경우의 수(최소) : %d\n", numOfCases);
    printf("동전의 수(최소) : %d\n", numOfCoins);
}

void FiniteCoin()
{
    int n = 0; // 동전 종류의 개수
    int k = 0; // 지폐의 금액
    vector<pair<int, int>> coins; // 동전 종류, 개수

    // [input2.txt]
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        pair<int, int> coin;

        scanf("%d %d", &coin.first, &coin.second);

        coins.push_back(coin);
    }

    int numOfCases = FiniteCoin_NumberOfCases(coins, k);
    int numOfCoins = FiniteCoin_NumberOfCoins(coins, k);

    printf("[동전 교환] - 동전의 개수 유한\n");
    printf("경우의 수(최소) : %d\n", numOfCases);
    printf("동전의 수(최소) : %d\n", numOfCoins);
}

// https://www.acmicpc.net/problem/2293
// http://comganet.github.io/dp/2016/06/03/dp-1002
int InfiniteCoins_NumberOfCases(vector<int>& coins, int k)
{
    int result = 0;

    vector<int> dp(k + 1, 0); // 0으로 초기화

    dp[0] = 1;

    for (int element : coins) // element = conins[i]
    {
        // 지폐의 금액이 j인 경우 (coins[i] ~ k)
        for (int j = element; j <= k; j++)
        {
            int total = j - element;

            // dp[j] : coins[i]를 포함 안하는 경우 (기존의 경우의 수)
            // dp[total] : coins[i]를 포함하는 경우 (새로운 경우의 수)
            dp[j] += dp[total];
        }
    }

    result = dp[k];

    return result;
}

// https://www.acmicpc.net/problem/2294
int InfiniteCoins_NumberOfCoins(vector<int>& coins, int k)
{
    int result = -1; // 경우의 수가 없으면 -1

    // 최댓값(k + 1)으로 초기화
    // 경우의 수 이므로 최솟값을 구해야 함
    vector<int> dp(k + 1, k + 1);

    dp[0] = 0;

    for (int element : coins) // element = conins[i]
    {
        // 지폐의 금액이 j인 경우 (coins[i] ~ k)
        for (int j = element; j <= k; j++)
        {
            int total = j - element;

            // dp[j] : coins[i]를 포함 안하는 경우 (기존의 개수)
            // dp[total] + 1 : coins[i]를 포함하는 경우 (새로운 개수)
            dp[j] = std::min(dp[j], dp[total] + 1);
        }
    }

    if (dp[k] < k + 1)
    {
        result = dp[k];
    }

    return result;
}

// https://www.acmicpc.net/problem/11047
// 위 문제의 정답은 맞지만, 최솟값이 아닌 것 같음 (DP 사용)
int InfiniteCoins_NumberOfCoins_Greedy(vector<int>& coins, int k)
{
    int result = 0;

    const int coinSize = coins.size();

    sort(coins.begin(), coins.end()); // 오름차순

    // k의 수가 매우 큰 경우 (ex. 100,000,000)
    for (int i = coinSize - 1; i >= 0; i--)
    {
        if (k != 0)
        {
            result += k / coins[i];
            k %= coins[i];
        }
        else
        {
            break;
        }
    }

    return result;
}

// https://www.acmicpc.net/problem/2624
// http://comganet.github.io/dp/2016/06/03/dp-1005
int FiniteCoin_NumberOfCases(vector<pair<int, int>>& coins, int k)
{
    int result = 0;

    vector<int> dp(k + 1, 0); // 0으로 초기화

    dp[0] = 1;

    for (auto element : coins) // element = conins[i]
    {
        int coin = element.first;
        int number = element.second;

        // 지폐의 금액이 j인 경우 (coins[i] ~ k)
        for (int j = k; j >= 1; j--)
        {
            // 동전의 개수가 n개인 경우 (1 ~ number)
            for (int n = 1; n <= number; n++)
            {
                int total = j - (coin * n);

                if (total >= 0)
                {
                    // dp[j] : coins[i]를 포함 안하는 경우 (기존의 경우의 수)
                    // dp[total] : coins[i]를 포함하는 경우 (새로운 경우의 수)
                    dp[j] += total;
                }
            }
        }
    }

    result = dp[k];

    return result;
}

int FiniteCoin_NumberOfCoins(vector<pair<int, int>>& coins, int k)
{
    int result = -1; // 경우의 수가 없으면 -1

    vector<int> dp(k + 1, k + 1); // 최댓값(k + 1)으로 초기화

    dp[0] = 0;

    for (auto element : coins) // element = conins[i]
    {
        int coin = element.first;
        int count = element.second;

        // 지폐의 금액이 j인 경우 (coins[i] ~ 1)
        for (int j = k; j >= 1; j--)
        {
            // 동전의 개수가 n개인 경우 (1 ~ number)
            for (int n = 1; n <= count; n++)
            {
                int total = j - (coin * n);

                if (total >= 0)
                {
                    // dp[j] : coins[i]를 포함 안하는 경우 (기존의 개수)
                    // dp[total] + 1 : coins[i]를 포함하는 경우 (새로운 개수)
                    dp[j] = std::min(dp[j], dp[total] + 1);
                }
            }
        }
    }

    if (dp[k] <= k)
    {
        result = dp[k];
    }
    else
    {
        // 경우의 수가 없으면 -1
    }

    return result;
}

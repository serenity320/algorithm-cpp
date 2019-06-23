#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// [배낭 문제]
// 배낭에 담을 수 있는 무게의 최댓값이 정해져 있고,
// 일정 가치와 무게가 있는 짐들을 배낭에 넣을 때,
// 가치의 합이 최대가 되도록 짐을 고르는 방법
int KnapsackProblem(vector<pair<int, int>> items, int w);

int main()
{
    int n = 0; // 짐의 개수
    int w = 0; // 배낭에 담을 수 있는 무게의 최댓값
    vector<pair<int, int>> items; // 짐의 무게, 가치(가격)

    // [input.txt]
    scanf("%d %d", &n, &w);

    for (int i = 0; i < n; i++)
    {
        int w = 0; // 짐의 무게
        int p = 0; // 짐의 가격

        scanf("%d %d", &w, &p);

        items.push_back(make_pair(w, p));
    }

    int result = KnapsackProblem(items, w);

    printf("%d\n", result);

    return 0;
}

int KnapsackProblem(vector<pair<int, int>> items, int w)
{
    int result = 0;

    // 0으로 초기화
    // 최대 무게이므로 최댓값을 구해야 함
    vector<int> dp(w + 1, 0);

    for (auto element : items) // element = items[i]
    {
        int weight = element.first; // 무게
        int value = element.second; // 가치

         // 제한된 무게가 j인 경우 (w ~ weight)
        for (int j = w; j >= weight; j--)
        {
            int total = j - weight;

            // dp[j] : items[i]를 포함 안하는 경우 (기존의 가치)
            // dp[total] + value : items[i]를 포함하는 경우 (새로운 가치)
            dp[j] = std::max(dp[j], dp[total] + value);
        }
    }

    result = dp[w];

    return result;
}

#include <cstdio>
#include <vector>

#define LIMIT 1000000000

using namespace std;

int main()
{    int result = 0;

    vector<int64_t> data;
    const int N = data.size();

    // Input
    //data.push_back(input);

    // Algorithm
    for (int i = 0; i < N; i++)
    {
        int64_t mod = 0;

        mod = data[i] % LIMIT; // input이 LIMIT보다 큰 경우
        mod = (result + mod) % LIMIT;
        result = static_cast<int>(mod);

        // SUM = 73218445
        // SUM of MOD = 10073218450
    }

    // Output
    printf("%d\n", result);

    return 0;
}

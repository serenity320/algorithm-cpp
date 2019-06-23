#include <cstdio>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main()
{
    vector<int> A;

    // [Input]
    {
        int N = 0;

        scanf("%d", &N);

        for (int i = 0; i < N; i++)
        {
            int num = 0;

            scanf("%d", &num);

            A.push_back(num);
        }
    }

    int result = solution(A);

    printf("%d\n", result);

    return 0;
}

// [Solution]
// Programming language : C++

//#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>

int solution(vector<int> &A)
{
    int result = 0;

    const int N = A.size();

    // #include <limits>
    // (#include <vector>)
    constexpr auto minInt32 = std::numeric_limits<int>::min();
    constexpr auto maxInt32 = std::numeric_limits<int>::max();

    // #include <cmath>
    {
        int absNumber = std::abs(result);
        double powNumber = std::pow(2, result);
        double sqrtNumber = std::sqrt(result);
    }

    // #include <algorithm>
    {
        int minNumber = std::min(maxInt32, result);
        int maxNumer = std::max(minInt32, result);

        int minElement = *std::min_element(A.begin(), A.end());
        int maxElement = *std::max_element(A.begin(), A.end());

        std::sort(A.begin(), A.end()); // ASC(Order)
        std::sort(A.begin(), A.end(), std::greater<int>()); // DRSC(Inorder)
    }

    // #include <numeric>
    {
        int initSum = 0;
        int sum = std::accumulate(A.begin(), A.end(), initSum);
    }

    // #include <string>
    {
        string str = "ABCDEFG";
        string subStr = str.substr(2, 3); // "CDEFG"
        char ch = str[3]; // 'D'
    }

    // #include <vector>
    {
        for (int element : A)
        {
            int number = element;
        }

        for (auto iter = A.begin(); iter != A.end(); ++iter)
        {
            int number = *iter;
        }

        for (size_t i = 0; i < A.size(); i++)
        {
            int number = A[i];
        }
    }

    return result;
}

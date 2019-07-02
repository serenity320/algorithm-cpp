#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// https://codility.com/media/train/7-MaxSlice.pdf
int MaximumSubarray1(vector<int>& data); // O(N^3)
int MaximumSubarray2(vector<int>& data); // O(N^2)
int MaximumSubarray3(vector<int>& data, int left, int right); // O(NlogN)
int MaximumSubarray4(vector<int>& data); // O(N)
int MaximumSubarray5(vector<int>& data); // O(N) [== MaximumSubarray4()]

int main()
{
    vector<int> data = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 }; // result = 187
    //vector<int> data = { -31, -41, -59, -26, -53, -58, -97, -93, -23, -84 }; // result = -23
    //vector<int> data = { -5, -7, 3, 5, -2, 4, -1 }; // result = 10

    int result1 = MaximumSubarray1(data);
    int result2 = MaximumSubarray2(data);
    int result3 = MaximumSubarray3(data, 0, data.size() - 1);
    int result4 = MaximumSubarray4(data);
    int result5 = MaximumSubarray5(data);

    printf("O(N^3)   : %d\n", result1);
    printf("O(N^2)   : %d\n", result2);
    printf("O(NlogN) : %d\n", result3);
    printf("O(N)     : %d\n", result4);
    printf("O(N)     : %d\n", result5);

    return 0;
}

int MaximumSubarray1(vector<int>& data)
{
    int result = 0;

    // [Subarray의 size가 0이 될 수 있다면,]
    // int maxSum = 0;
    int maxSum = std::numeric_limits<int>::min();
    int sum = 0;

    for (size_t i = 0; i < data.size(); i++)
    {
        for (size_t j = i; j < data.size(); j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += data[k];
            }

            maxSum = std::max(maxSum, sum);
        }
    }

    result = maxSum;

    return result;
}

int MaximumSubarray2(vector<int>& data)
{
    int result = 0;

    // [Subarray의 size가 0이 될 수 있다면,]
    // int maxSum = 0;
    int maxSum = std::numeric_limits<int>::min();
    int sum = 0;

    for (size_t i = 0; i < data.size(); i++)
    {
        int sum = 0;

        for (size_t j = i; j < data.size(); j++)
        {
            sum += data[j];
            maxSum = std::max(maxSum, sum);
        }
    }

    result = maxSum;

    return result;
}

int MaximumSubarray3(vector<int>& data, int left, int right)
{
    int result = 0;

    if (left == right)
    {
        result = data[left];
    }
    else
    {
        // [Subarray의 size가 0이 될 수 있다면,]
        //int maxLeftCenter = 0;
        //int maxRightCenter = 0;
        int maxLeftCenter = std::numeric_limits<int>::min();
        int maxRightCenter = std::numeric_limits<int>::min();

        int center = (left + right) / 2;
        int maxLeft = MaximumSubarray3(data, left, center);
        int maxRight = MaximumSubarray3(data, center + 1, right);

        int sum = 0;

        for (int i = center; i >= left; i--)
        {
            sum = sum + data[i];
            maxLeftCenter = std::max(maxLeftCenter, sum);
        }

        sum = 0;
        for (int i = center + 1; i <= right; i++)
        {
            sum = sum + data[i];
            maxRightCenter = std::max(maxRightCenter, sum);
        }

        int maxCenter = maxLeftCenter + maxRightCenter;

        result = std::max(std::max(maxLeft, maxRight), maxCenter);
    }

    return result;
}

int MaximumSubarray4(vector<int>& data)
{
    int result = 0;

    // [Subarray의 size가 0이 될 수 있다면,]
    // int maxSum = 0;
    int maxSum = std::numeric_limits<int>::min();
    int sum = 0;

    for (int element : data)
    {
        sum = std::max(element, sum + element);
        maxSum = std::max(maxSum, sum);
    }

    result = maxSum;

    return result;
}

int MaximumSubarray5(vector<int>& data)
{
    vector<int> maxSum(data.size(), 0); // sum

    maxSum[0] = data[0];

    for (auto i = 1; i < data.size(); i++)
    {
        // [Subarray의 size가 0이 될 수 있다면,]
        // maxSum[i] = std::max(0, maxSum[i - 1] + data[i]);
        maxSum[i] = std::max(data[i], maxSum[i - 1] + data[i]);
    }

    auto result = std::max_element(maxSum.begin(), maxSum.end());

    return *result;
}

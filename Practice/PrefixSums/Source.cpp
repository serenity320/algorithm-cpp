#include <cstdio>
#include <vector>

using namespace std;

vector<int> PrefixSums(vector<int>& data); // 정순
vector<int> PrefixSums_InverseOrder(vector<int>& data); // 역순

// data[p] ~ data[q]의 합 (p <= q)
int SliceSum(vector<int>& data, int p, int q); // 정순
int SliceSum_InverseOrder(vector<int>& data, int p, int q); // 역순

int main()
{
    vector<int> data = { 1, 2, 3, 4, 5 };
    int p = 1;
    int q = 3;

    printf("[SliceSum] - Order\n");
    {
        int result = SliceSum(data, p, q);

        printf("%d\n", result);
    }

    printf("\n\n");

    printf("[SliceSum] - InverseOrder\n");
    {
        int result = SliceSum_InverseOrder(data, p, q);

        printf("%d\n", result);
    }

    return 0;
}

vector<int> PrefixSums(vector<int>& data)
{
    vector<int> result(data.size(), 0);

    if (!data.empty())
    {
        result[0] = data[0];
    }

    // Time Complexity : O(N)
    // Space Complexity : O(N)
    for (size_t i = 1; i < data.size(); i++)
    {
        result[i] = result[i - 1] + data[i];
    }

    return result;
}

vector<int> PrefixSums_InverseOrder(vector<int>& data)
{
    vector<int> result(data.size(), 0);

    int lastIndex = data.size() - 1;

    if (!data.empty())
    {
        result[lastIndex] = data[lastIndex];
    }

    // Time Complexity : O(N)
    // Space Complexity : O(N)
    for (int i = lastIndex - 1; i >= 0; i--)
    {
        result[i] = result[i + 1] + data[i];
    }

    return result;
}

int SliceSum(vector<int>& data, int p, int q)
{
    int result = 0;

    vector<int> sums = PrefixSums(data);
    int sumsP = 0;

    if (p - 1 >= 0)
    {
        sumsP = sums[p - 1];
    }

    // Time Complexity : O(1)
    // Space Complexity : O(1)
    result = sums[q] - sumsP;

    return result;
}

int SliceSum_InverseOrder(vector<int>& data, int p, int q)
{
    int result = 0;

    vector<int> sums = PrefixSums_InverseOrder(data);
    int sumq = 0;

    if (q + 1 < data.size())
    {
        sumq = sums[q + 1];
    }

    // Time Complexity : O(1)
    // Space Complexity : O(1)
    result = sums[p] - sumq;

    return result;
}

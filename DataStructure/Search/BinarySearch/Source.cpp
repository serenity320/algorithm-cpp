#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void BinarySearch(vector<int>& data, int search);

int main()
{
    //vector<int> data = { 1, 2, 3, 4, 5 };
    vector<int> data = { 1, 5, 7, 15, 20, 21 };
    int search = 17; // 찾으려는 값

    // 필요에 따라 정렬(Sort)
    std::sort(data.begin(), data.end());

    BinarySearch(data, search);

    return 0;
}

void BinarySearch(vector<int>& data, int search)
{
    int left = 0;
    int right = data.size() - 1;
    int middle = 0;

    do
    {
        middle = (left + right) / 2;

        if (data[middle] > search)
        {
            right = middle - 1;
        }
        else if (data[middle] < search)
        {
            left = middle + 1;
        }
        else // data[middle] == search
        {
            break;
        }
    } while (left <= right);

    if (left > right)
    {
        int leftDiff = search - data[right];
        int rightDiff = data[left] - search;

        printf("data에 %d가 존재하지 않음\n", search);
        printf("-> data[%d](%d)와 data[%d](%d) 사이에 존재\n", right, data[right], left, data[left]);

        if (leftDiff < rightDiff)
        {
            printf("-> data[%d](%d)에 더 가깝게 위치\n", right, data[right]);
        }
        else if (leftDiff > rightDiff)
        {
            printf("-> data[%d](%d)에 더 가깝게 위치\n", left, data[left]);
        }
        else
        {
            printf("-> 정확히 중간에 위치\n");
        }
    }
    else
    {
        printf("%d는 data[%d]에 있음\n", search, middle);
    }
}
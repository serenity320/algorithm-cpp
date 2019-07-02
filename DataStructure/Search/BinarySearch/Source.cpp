#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> BinarySearch(vector<int>& data, int search);

int main()
{
    //vector<int> data = { 1, 2, 3, 4, 5 };
    vector<int> data = { 1, 5, 7, 15, 20, 21 };
    int search = 2; // 찾으려는 값

    // 필요에 따라 정렬(Sort)
    std::sort(data.begin(), data.end());

    auto result = BinarySearch(data, search);

    int left = result.first;
    int right = result.second;

    if (left == right)
    {
        int middle = left;

        printf("%d는 data[%d]에 있음\n", search, middle);
    }
    else if (left >= 0 && right <= data.size() - 1)
    {
        int leftDiff = search - data[right];
        int rightDiff = data[left] - search;

        printf("data에 %d이(가) 존재하지 않음\n", search);
        printf("-> data[%d](%d)와 data[%d](%d) 사이에 존재\n", left, data[left], right, data[right]);

        if (leftDiff < rightDiff)
        {
            printf("-> data[%d](%d)에 더 가깝게 위치\n", left, data[left]);
        }
        else if (leftDiff > rightDiff)
        {
            printf("-> data[%d](%d)에 더 가깝게 위치\n", right, data[right]);
        }
        else
        {
            printf("-> 정확히 중간에 위치\n");
        }
    }
    else
    {
        printf("%d은(는) 범위 이외에 있음\n", search);
    }

    return 0;
}

pair<int, int> BinarySearch(vector<int>& data, int search)
{
    pair<int, int> result(0, 0);

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
        result.first = right; // left
        result.second = left; // right
    }
    else
    {
        result.first = middle; // left
        result.second = middle; // right
    }

    return result;
}

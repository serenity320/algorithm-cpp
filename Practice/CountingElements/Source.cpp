#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> CountingElements_Vector(vector<int>& data);
map<int, int> CountingElements_Map(vector<int>& data);

int main()
{
    vector<int> data = { 1, 1, 2, 3, 3, 4, 5, 5 };

    printf("[Counting Elements] - Vector\n");
    {
        vector<int> result = CountingElements_Vector(data);

        for (size_t i = 0; i < result.size(); i++)
        {
            if (result[i] > 0)
            {
                printf("[%d] %d\n", i, result[i]);
            }
        }
    }

    printf("\n\n");

    printf("[Counting Elements] - Map\n");
    {
        map<int, int> result = CountingElements_Map(data);

        for (auto element : result)
        {
            printf("[%d] %d\n", element.first, element.second);
        }
    }

    return 0;
}

vector<int> CountingElements_Vector(vector<int>& data)
{
    // data에 음수(-)가 포함되면 vector의 공간을 확장해야 함
    // data의 크기(size)가 너무 크면 vector 할당이 어려움

    vector<int> result;

    auto max = *std::max_element(data.begin(), data.end());

    result.assign(max + 1, 0);

    // N : data.size()
    // M : m(data의 원소 중 최댓값)

    // Time Complexity : O(N + M)
    // Space Complexity : O(M)
    for (int element : data)
    {
        result[element]++;
    }

    return result;
}

map<int, int> CountingElements_Map(vector<int>& data)
{
    // 음수(-) 및 공간 할당에 대한 문제는 없지만,
    // data를 Map으로 만드는 시간 복잡도가 비교적 큼

    map<int, int> result;

    // Time Complexity : O(NlogN)
    // Space Complexity : O(N)
    for (int element : data)
    {
        result[element]++;
    }

    return result;
}

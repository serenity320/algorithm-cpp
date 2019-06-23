#include <cstdio>
#include <vector>

using namespace std;

vector<int> ArrayPeak(vector<int>& data);

int main()
{
    vector<int> data = { 1, 2, 3, 4, 3, 4, 1, 2 ,3, 4, 6, 2 };

    vector<int> result = ArrayPeak(data);

    for (int element : result)
    {
        printf("data[%d] : %d\n", element, data[element]);
    }

    return 0;
}

vector<int> ArrayPeak(vector<int>& data)
{
    vector<int> result;

    const int N = data.size();

    for (int i = 1; i < N - 1; i++)
    {
        // 0 < P < N − 1
        // data[P − 1] < data[P] > data[P + 1]
        if (data[i - 1] < data[i] &&
            data[i] > data[i + 1])
        {
            result.push_back(i);
        }
    }

    return result;
}

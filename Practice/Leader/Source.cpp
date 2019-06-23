#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool Leader(vector<int>& data, int& leader);

int main()
{
    vector<int> data = { 6, 8, 4, 6, 8, 6, 6 };

    int leader = 0;
    bool result = Leader(data, leader);

    if (result)
    {
        printf("%d\n", leader);
    }

    return 0;
}

bool Leader(vector<int>& data, int& leader)
{
    bool result = false;

    int candidate = 0;
    int size = 0;

    leader = 0;

    // Time Complexity : O(N)
    // Space Complexity : O(N)
    for (int element : data)
    {
        if (size == 0)
        {
            candidate = element;
            size++;            
        }
        else
        {
            if (candidate != element)
            {
                size--;
            }
            else
            {
                size++;
            }
        }
    }

    if (size > 0)
    {
        int count = std::count(data.begin(), data.end(), candidate);

        if (count > data.size() / 2)
        {
            leader = candidate;
            result = true;
        }
    }

    return result;
}

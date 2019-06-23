#include <cstdio>
#include <vector>
#include <set>

using namespace std;

set<int> SortingUnique(vector<int>& data);

int main()
{
    vector<int> data = { 5, 5, 4, 3, 3, 2, 1, 1 };

    set<int> result = SortingUnique(data);

    for (auto element : result)
    {
        printf("%d ", element);
    }

    printf("\n");

    return 0;
}

set<int> SortingUnique(vector<int>& data)
{
    set<int> result;
 
    // Time Complexity : O(NlogN)
    // Space Complexity : O(N)
    for (int element : data)
    {
        // Time Complexity : O(logN)
        auto pair = result.insert(element);

        if (!pair.second)
        {
            // Element already exists.
        }
    }
    
    return result;
}

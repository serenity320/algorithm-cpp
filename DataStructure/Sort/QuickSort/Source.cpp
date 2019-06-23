#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void BinarySearch(vector<int>& data, int search);

int main()
{
    vector<int> data = { 1, 5, 7, 15, 20, 21 };

    // Quick Sort - ASC(Order)
    std::sort(data.begin(), data.end()); 

    // Quick Sort - DESC(Inorder)
    std::sort(data.begin(), data.end(), std::greater<int>());

    return 0;
}
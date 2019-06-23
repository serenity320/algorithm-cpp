#include <iostream>
#include <set>

using namespace std;

int main()
{
    // http://en.cppreference.com/w/cpp/container/set
    // http://www.cplusplus.com/reference/set/set/

    // https://twpower.github.io/92-how-to-use-set-in-cpp

    set<int> values; // Set

    // [Modifiers]
    {
        // clear()
        values.clear();

        // insert(element)
        values.insert(1);
        values.insert(2);
        values.insert(3);

        auto result = values.insert(1);// set
        // result.first : key(1)의 iterator
        // result.second : 중복 여부 (true : 중복 X)

        // erase(element)
        values.erase(2);
    }

    // [Capacity]
    {
        // empty()
        bool isEmpty = values.empty();
        cout << "isEmpty : " << isEmpty << '\n';

        // size()
        size_t size = values.size();
        cout << "size : " << size << '\n';
    }

    // [Operations]
    {
        // find(element)
        auto iterator = values.find(1);
        if (iterator != values.end())
        {
            cout << "element : " << *iterator << '\n';
        }

        // count(element)
        auto count = values.count(1); // set은 무조건 1
        cout << "count : " << count << '\n';
    }

    // [Iterators]
    for (auto iter = values.begin(); iter != values.end(); ++iter)
    {
        cout << "value : " << *iter << '\n';
    }

    // [Iterators - Foreach]
    for (auto element : values)
    {
        cout << "value : " << element << "\n";
    }

    return 0;
}

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    // http://en.cppreference.com/w/cpp/container/forward_list
    // http://www.cplusplus.com/reference/forward_list/forward_list/

    forward_list<int> values; // Forward list

    // [Modifiers]
    {
        // clear()
        values.clear();

        // assign(size, element)
        values.assign(10, 0); // 0으로 초기화

        // push_front(element)
        values.push_front(1);
        values.push_front(2);

        // pop_front()
        values.pop_front();

        // insert_after()
        // http://en.cppreference.com/w/cpp/container/forward_list/insert_after
        // http://www.cplusplus.com/reference/forward_list/forward_list/insert_after/

        // erase_after()
        // http://en.cppreference.com/w/cpp/container/forward_list/erase_after
        // http://www.cplusplus.com/reference/forward_list/forward_list/erase_after/
    }

    // [Element access]
    {
        // front()
        if (!values.empty())
        {
            auto front = values.front();
        }
    }

    // [Capacity]
    {
        // empty()
        bool isEmpty = values.empty();
        cout << "isEmpty : " << isEmpty << '\n';
    }

    // [Iterators]
    for (auto iter = values.begin(); iter != values.end(); ++iter)
    {
        cout << "value : " << *iter << "\n";
    }

    // [Iterators - Foreach]
    for (auto element : values)
    {
        cout << "value : " << element << "\n";
    }

    return 0;
}

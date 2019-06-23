#include <iostream>
#include <list>

using namespace std;

int main()
{
    // http://en.cppreference.com/w/cpp/container/list
    // http://www.cplusplus.com/reference/list/list/

    // https://twpower.github.io/78-how-to-use-list-in-cpp

    list<int> values; // List

    // [Modifiers]
    {
        // clear()
        values.clear();

        // assign(size, element)
        values.assign(10, 0); // 0으로 초기화

        // push_front(element)
        values.push_front(1);
        values.push_front(2);

        // push_back(element)
        values.push_back(3);
        values.push_back(4);
        values.push_back(5);

        // pop_front()
        values.pop_front();

        // pop_back()
        values.pop_back();

        // insert()
        // http://en.cppreference.com/w/cpp/container/list/insert
        // http://www.cplusplus.com/reference/vector/list/insert/

        // erase()
        // http://en.cppreference.com/w/cpp/container/list/erase
        // http://www.cplusplus.com/reference/list/list/erase/
    }

    // [Element access]
    {
        // front()
        if (!values.empty())
        {
            auto front = values.front();
        }

        // back()
        if (!values.empty())
        {
            auto back = values.back();
        }
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

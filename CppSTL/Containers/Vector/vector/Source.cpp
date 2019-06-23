#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // http://en.cppreference.com/w/cpp/container/vector
    // http://www.cplusplus.com/reference/vector/

    // https://twpower.github.io/77-how-to-use-vector-in-cpp

    vector<int> values; // Vector

    // [Modifiers]
    {
        // clear()
        values.clear();

        // assign(size, element)
        values.assign(10, 0); // 0으로 초기화

        // push_back(element)
        values.push_back(1);
        values.push_back(2);
        values.push_back(3);

        // pop_back()
        values.pop_back();

        // insert()
        // http://en.cppreference.com/w/cpp/container/vector/insert
        // http://www.cplusplus.com/reference/vector/vector/insert/

        // erase()
        // http://en.cppreference.com/w/cpp/container/vector/erase
        // http://www.cplusplus.com/reference/vector/vector/erase/
    }

    // [Element access]
    {
        // operator[index]
        if (values.size() > 0)
        {
            values[0] = 0; // value
        }

        // at(index)   
        if (values.size() > 0)
        {
            auto value = values.at(0);
        }

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

        // reverse()
        values.reserve(values.size());

        // size()
        size_t size = values.size();
        cout << "size : " << size << '\n';
    }

    // [Iterators]
    for (auto iter = values.begin(); iter != values.end(); ++iter)
    {
        cout << *iter << "\n";
    }

    // [Iterators - Foreach]
    for (auto element : values)
    {
        cout << "value : " << element << "\n";
    }
    
    // [Loop]
    for (size_t i = 0; i < values.size(); i++)
    {
        cout << "value : " << values[i] << "\n";
    }

    return 0;
}

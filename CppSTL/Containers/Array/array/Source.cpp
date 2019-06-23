#include <iostream>
#include <array>

using namespace std;

int main()
{
    // http://en.cppreference.com/w/cpp/container/array
    // http://www.cplusplus.com/reference/array/array/

    array<int, 10> values; // Array class

    // [Modifiers]
    {
        // fill(element)
        values.fill(0); // 0으로 초기화
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

        // data()
        int* pData = values.data();
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

    // [Convert Array]
    {
        // C Array -> std::array
        int cArray[5] = { 1, 2, 3, 4, 5 };
        array<int, 5> stdArray; // Array class
        std::copy(std::begin(cArray), std::end(cArray), std::begin(stdArray));

        // std::array -> C Array
        int* pArray = stdArray.data();
        std::memcpy(pArray, cArray, stdArray.size());
    }

    return 0;
}

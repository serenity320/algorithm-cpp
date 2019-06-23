#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // http://en.cppreference.com/w/cpp/container/stack
    // http://www.cplusplus.com/reference/queue/stack/

    // https://twpower.github.io/75-how-to-use-stack-in-cpp

    stack<int> values; // LIFO stack

    // [Modifiers]
    {
        // push(element)
        values.push(1);
        values.push(2);
        values.push(3);

        // pop()
        values.pop();
    }

    // [Element access]
    {
        // front()
        if (!values.empty())
        {
            auto front = values.top();
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

    // [Loop]
    while (!values.empty())
    {
        cout << "value : " << values.top() << "\n";
        values.pop();
    }

    return 0;
}

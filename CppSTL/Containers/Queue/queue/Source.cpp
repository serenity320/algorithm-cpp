#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // http://en.cppreference.com/w/cpp/container/queue
    // http://www.cplusplus.com/reference/queue/queue/

    // https://twpower.github.io/76-how-to-use-queue-in-cpp

    queue<int> values; // FIFO queue

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

    // [Loop]
    while (!values.empty())
    {
        cout << values.front() << "\n";
        values.pop();
    }

    return 0;
}

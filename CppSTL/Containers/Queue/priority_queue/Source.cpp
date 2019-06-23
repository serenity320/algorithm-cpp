#include <iostream>
#include <functional>
#include <queue>

using namespace std;

struct Item
{
    int x;
    int y;
    int value;
    
    Item(int value) :
        x(0), y(0), value(value)
    {

    }
};

struct Compare
{
    bool operator()(Item a, Item b)
    {
        return a.value > b.value; // ASC
    }
};

int main()
{
    // http://en.cppreference.com/w/cpp/container/priority_queue
    // http://www.cplusplus.com/reference/queue/priority_queue/

    // https://twpower.github.io/93-how-to-use-priority_queue-in-cpp

    priority_queue<int> values; // Priority queue (Max Heap, DESC)
    priority_queue<int, vector<int>, less<int>> values_desc; // Priority queue (Max Heap, DESC)
    priority_queue<int, vector<int>, greater<int>> values_asc; // Priority queue (Min Heap, ASC)
    priority_queue<Item, vector<Item>, Compare> values_custom; // Priority queue (Custom)

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
        // top()
        if (!values.empty())
        {
            auto top = values.top();
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
        cout << values.top() << "\n";
        values.pop();
    }

    return 0;
}

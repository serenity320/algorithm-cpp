#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Item
{
    int A;
    int B;
    int C;
    int D;

    bool const operator<(const Item& item) const
    {
        return (A < item.A ||
            (A == item.A && B < item.B) ||
            ((A == item.A && B == item.B) && C < item.C) ||
            (((A == item.A && B == item.B) && C == item.C) && D < item.D));
    }
};

int main()
{
    // http://en.cppreference.com/w/cpp/container/map
    // http://www.cplusplus.com/reference/map/

    // https://twpower.github.io/92-how-to-use-map-in-cpp

    map<string, int> data; // Map
    map<Item, int> values_custum; // Map

    // [Modifiers]
    {
        // clear()
        data.clear();

        // insert(<key, value>)
        data.insert(make_pair("ABC", 1));
        data.insert(make_pair("DEF", 2));
        data.insert(make_pair("GHI", 3));

        auto result = data.insert(make_pair("ABC", 1));
        // result.first : key("ABC")의 iterator
        // result.second : 중복 여부 (true : 중복 X)

        // erase(key)
        data.erase("DEF");
    }

    // [Element access]
    {
        // operator[key]
        if (data.count("ABC") > 0)
        {
            data["ABC"] = 0; // value
        }

        // at(key)
        if (data.count("ABC") > 0)
        {
            auto value = data.at("ABC");
        }
    }

    // [Capacity]
    {
        // empty()
        bool isEmpty = data.empty();
        cout << "isEmpty : " << isEmpty << '\n';

        // size()
        size_t size = data.size();
        cout << "size : " << size << '\n';
    }

    // [Operations]
    {
        // find(key)
        auto element = data.find("ABC");
        if (element != data.end())
        {
            cout << "key : " << element->first << ", value : " << element->second << '\n';
        }

        // count(key)
        auto count = data.count("ABC"); // map은 무조건 1
        cout << "count : " << count << '\n';
    }

    // [Iterators]
    for (auto iter = data.begin(); iter != data.end(); ++iter)
    {
        cout << "key : " << iter->first << ", value : " << iter->second << '\n';
    }

    // [Iterators - Foreach]
    for (auto element : data)
    {
        cout << "key : " << element.first << ", value : " << element.second << '\n';
    }

    return 0;
}

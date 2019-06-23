#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    // http://en.cppreference.com/w/cpp/container/unordered_map
    // http://www.cplusplus.com/reference/unordered_map/

    unordered_map<string, int> values; // Unordered Map

    // [Modifiers]
    {
        // clear()
        values.clear();

        // insert(<key, value>)
        values.insert(make_pair("ABC", 1));
        values.insert(make_pair("DEF", 2));
        values.insert(make_pair("GHI", 3));

        auto result = values.insert(make_pair("ABC", 1));
        // result.first : key("ABC")의 iterator
        // result.second : 중복 여부 (true : 중복 X)

        // erase(key)
        values.erase("DEF");
    }

    // [Element access]
    {
        // operator[key]
        if (values.count("ABC") > 0)
        {
            values["ABC"] = 0; // value
        }

        // at(key)
        if (values.count("ABC") > 0)
        {
            auto value = values.at("ABC");
        }
    }

    // [Capacity]
    {
        // empty()
        bool isEmpty = values.empty();
        cout << "isEmpty : " << isEmpty << '\n';

        // size()
        size_t size = values.size(); // set은 무조건 1
        cout << "size : " << size << '\n';
    }

    // [Operations]
    {
        // find(key)
        auto element = values.find("ABC");
        if (element != values.end())
        {
            cout << "key : " << element->first << ", value : " << element->second << '\n';
        }

        // count(key)
        auto count = values.count("ABC"); // map은 무조건 1
        cout << "count : " << count << '\n';
    }

    // [Iterators]
    for (auto iter = values.begin(); iter != values.end(); ++iter)
    {
        cout << "key : " << iter->first << ", value : " << iter->second << '\n';
    }

    // [Iterators - Foreach]
    for (auto element : values)
    {
        cout << "key : " << element.first << ", value : " << element.second << '\n';
    }

    return 0;
}

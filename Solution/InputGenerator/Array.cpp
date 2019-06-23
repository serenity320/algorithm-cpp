#include "Array.h"

string ConvertArray()
{
    int number = 0;
    vector<int> data;

    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        int value = 0;

        scanf("%d", &value);

        data.push_back(value);
    }

    string result = "[";
    for (size_t i = 0; i < data.size(); i++)
    {
        result += to_string(data[i]);

        if (i <  data.size() - 1)
        {
            result += ", ";
        }
    }
    result += "]";

    return result;
}

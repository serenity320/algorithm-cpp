#include <iostream>
#include <vector>

#include <limits>

using namespace std;

int main()
{
    vector<int> data(10, 0);

    // [Type support]
    // https://en.cppreference.com/w/cpp/types
    {
        // [Numeric limits]
        {
            // numeric_limits<T>
            // https://en.cppreference.com/w/cpp/types/numeric_limits
            {
                auto int32_min = std::numeric_limits<int>::min(); // 0x80000000
                auto int32_max = std::numeric_limits<int>::max(); // 0x7FFFFFFF
                auto int32_lowest = std::numeric_limits<int>::lowest();
                auto int32_infinity = std::numeric_limits<int>::infinity();
                // int32_min: -2147483648 (INT_MIN)
                // int32_max: 2147483647 (INT_MAX)
                // int32_lowest: -2147483648
                // int32_infinity:  0

                auto uint32_min = std::numeric_limits<uint32_t>::min(); // 0x00000000
                auto uint32_max = std::numeric_limits<uint32_t>::max(); // 0x80000000
                auto uint32_lowest = std::numeric_limits<uint32_t>::lowest();
                auto uint32_infinity = std::numeric_limits<uint32_t>::infinity();
                // int32_min: -2147483648
                // int32_max: 4294967295 (UINT32_MAX)
                // int32_lowest: 0
                // int32_infinity:  0

                auto double_min = std::numeric_limits<double>::min();
                auto double_max = std::numeric_limits<double>::max();
                auto double_lowest = std::numeric_limits<double>::lowest();
                auto double_infinity = std::numeric_limits<double>::infinity();
                // double_min: 2.2250738585072014e-308 (DBL_MIN)
                // double_max: 1.7976931348623157e+308 (DBL_MAX)
                // double_lowest: -1.7976931348623157e+308 (-DBL_MAX)
                // double_infinity: inf (HUGE_VAL)

                // double_infinity > double_lowest
            }
        }
    }

    return 0;
}

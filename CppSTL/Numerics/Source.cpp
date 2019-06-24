#include <iostream>
#include <functional>
#include <string>
#include <vector>

#include <cmath>
#include <numeric>

using namespace std;

int main()
{
    // [Mathematical functions and types]
    // https://en.cppreference.com/w/cpp/numeric
    {
        // [Common mathematical functions]
        // https://en.cppreference.com/w/cpp/numeric/math
        {
            // [Basic operations]
            {
                // abs()
                // https://en.cppreference.com/w/cpp/numeric/math/abs
                {
                    int result1 = std::abs(-3);
                    // result1: 3

                    double result2 = std::abs(-3.0);
                    // result2: 3.0
                }

                // log()
                // https://en.cppreference.com/w/cpp/numeric/math/log
                {
                    double result = std::log(3);
                    // result: 1.0986122886681098
                }

                // log10()
                // https://en.cppreference.com/w/cpp/numeric/math/log10
                {
                    double result = std::log10(3);
                    // result: 0.47712125471966244
                }

                // log2()
                // https://en.cppreference.com/w/cpp/numeric/math/log2
                {
                    double result = std::log2(3);
                    // result: 1.5849625007211561
                }
            }

            // [Power functions]
            {
                // pow()
                // https://en.cppreference.com/w/cpp/numeric/math/pow
                {
                    double result = std::pow(2, 10);
                    // result: 8.0000000000000000
                }

                // sqrt()
                // https://en.cppreference.com/w/cpp/numeric/math/sqrt
                {
                    double result = std::sqrt(3);
                    // result: 1.7320508075688772
                }
            }

            // [Macro constants]
            {
                cout << INFINITY << '\n';
                // inf

                if (numeric_limits<int>::max() > INFINITY)
                {
                    cout << std::numeric_limits<int>::max() << " < " << INFINITY << '\n';
                }
                // 2147483647 < inf
            }
        }
    }

    // [Numeric algorithms]
    {
        // [Numeric operations]
        {
            // iota()
            // https://en.cppreference.com/w/cpp/algorithm/iota
            {
                vector<int> values(10, 0);

                std::iota(values.begin(), values.end(), 1);
                // values: 1 2 3 4 5 6 7 8 9 10
            }

            // accumulate()
            // https://en.cppreference.com/w/cpp/algorithm/accumulate
            {
                vector<int> values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

                int sum = std::accumulate(values.begin(), values.end(), 0);
                // sum: 55

                int initSum = 100;
                int accumSum = std::accumulate(values.begin(), values.end(), initSum);
                // accumSum: 155

                int64_t initProduct = 1;
                int64_t product = std::accumulate(values.begin(), values.end(), initProduct, multiplies<int64_t>());
                // product: 3628800

                auto op = [](string str, int num)
                {
                    return str + ", " + to_string(num); // #include <string>
                };

                string result = std::accumulate(
                    next(values.begin()),
                    values.end(),
                    to_string(values[0]), // start with first element
                    op);
                // result: "1, 2, 3, 4, 5, 6, 7, 8, 9 "
            }

            // partial_sum()
            // https://en.cppreference.com/w/cpp/algorithm/partial_sum
            {
                vector<int> values(10, 2);
                // values: 2 2 2 2 2 2 2 2 2 2

                vector<int> partialSum;
                std::partial_sum(values.begin(), values.end(), std::back_inserter(partialSum));
                // values: 2 4 6 8 10 12 14 16 18 20

                vector<int> partialProduct;
                std::partial_sum(values.begin(), values.end(), std::back_inserter(partialProduct), multiplies<int>());
                // values: 2 4 8 16 32 64 128 256 512 1024
            }
        }
    }

    return 0;
}

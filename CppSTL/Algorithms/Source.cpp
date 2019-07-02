#include <iostream>
#include <functional>
#include <vector>

#include <algorithm>

using namespace std;

int main()
{
    // [Non-modifying sequence operations]
    {
        // all_of()
        // https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
        {
            // all_of()
            // 모든 원소가 조건에 만족
            {
                vector<int> values{ 2, 4, 6, 8, 10 };
                auto pred = [](int num) { return num % 2 == 0; };

                bool result = std::all_of(values.cbegin(), values.cend(), pred);
                // result: true
            }

            // none_of()
            // 모든 원소가 조건에 불만족
            {
                vector<int> values{ 1, 3, 5, 7, 9 };
                auto pred = [](int num) { return num % 2 == 0; };

                bool result = std::none_of(values.cbegin(), values.cend(), pred);
                // result: true
            }

            // any_of()
            // 적어도 한 개 이상의 원소가 조건에 만족
            {
                vector<int> values{ 1, 3, 5, 7, 9 };

                struct DivisibleBy
                {
                    const int divisor;
                    DivisibleBy(int n) : divisor(n) { }
                    bool operator()(int num) const { return num % divisor == 0; }
                };

                bool result = std::any_of(values.cbegin(), values.cend(), DivisibleBy(7));
                // result: true
            }
        }

        // for_each()
        // https://en.cppreference.com/w/cpp/algorithm/for_each
        {
            // Lambda
            {
                vector<int> values{ 1, 2, 3, 4, 5 };
                auto pred = [](int& num) { num++; };

                std::for_each(values.begin(), values.end(), pred);
                // values: 2 3 4 5 6
            }

            // Operator
            {
                vector<int> values{ 1, 2, 3, 4, 5 };

                struct Sum
                {
                    int result;
                    Sum() : result(0) { }
                    void operator()(int n) { result += n; }
                };

                Sum sum = std::for_each(values.begin(), values.end(), Sum());
                // sum.result: 15
            }
        }

        // count()
        // https://en.cppreference.com/w/cpp/algorithm/count
        {
            // count()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };
                int num = 3;

                int result = std::count(values.begin(), values.end(), num);
                // result: 1
            }

            // count_if()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };
                auto pred = [](int i) { return i % 2 == 0; };

                int result = std::count_if(values.begin(), values.end(), pred);
                // result: 2
            }
        }

        // find()
        // https://en.cppreference.com/w/cpp/algorithm/find
        {
            vector<int> values{ 1, 2, 3, 4, 5 };
            int num = 3;

            auto iterator = std::find(values.begin(), values.end(), num);

            bool result = iterator != values.end();
            // result: true

            if (result)
            {
                int index = std::distance(values.begin(), iterator);
                // index: 2
            }
        }

        // find_end()
        // https://en.cppreference.com/w/cpp/algorithm/find_end
        {
            vector<int> values{ 1, 2, 3, 4, 5 };
            vector<int> sub{ 2, 3, 4 };

            auto iterator = std::find_end(values.begin(), values.end(), sub.begin(), sub.end());

            bool result = (iterator != values.end());
            // result: true

            if (result)
            {
                int index = std::distance(values.begin(), iterator);
                // index: 2
            }
        }
    }

    // [Modifying sequence operations]
    {
        // copy()
        // https://en.cppreference.com/w/cpp/algorithm/copy
        {
            // copy()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };

                vector<int> copied1(values);
                // copied1 : 1 2 3 4 5

                vector<int> copied2(values.size());
                std::copy(values.begin(), values.end(), copied2.begin());
                // copied2 : 1 2 3 4 5

                vector<int> copied3;
                std::copy(values.begin(), values.end(), std::back_inserter(copied3));
                // copied3 : 1 2 3 4 5
            }

            // copy_if()
            {
                vector<int> values{ -2, -1, 0, 1, 2 };
                vector<int> copied;

                auto pred = [](int num) { return num >= 0; };

                copy_if(values.begin(), values.end(), std::back_inserter(copied), pred);
                // copied: 0 1 2
            }
        }

        // copy_n()
        // https://en.cppreference.com/w/cpp/algorithm/copy_n
        {
            vector<int> values{ 1, 2, 3, 4, 5 };
            vector<int> copied;

            std::copy_n(values.begin(), 3, std::back_inserter(copied));
            // copied: 1 2 3
        }

        // copy_backward()
        // https://en.cppreference.com/w/cpp/algorithm/copy_backward
        {
            vector<int> values{ 1, 2, 3, 4, 5 };
            vector<int> copied(10);

            std::copy_backward(values.begin(), values.end(), copied.end());
            // copied: 0 0 0 0 0 1 2 3 4 5
        }

        // fill()
        // https://en.cppreference.com/w/cpp/algorithm/fill
        {
            vector<int> values{ 1, 2, 3, 4, 5 };

            int num = 3;

            std::fill(values.begin(), values.end(), num);
            // values: 3 3 3 3 3
        }

        // fill_n()
        // https://en.cppreference.com/w/cpp/algorithm/fill_n
        {
            vector<int> values{ 1, 2, 3, 4, 5 };

            int num = 3;

            std::fill_n(values.begin(), 5, num);
            // values: 3 3 3 4 5
        }

        // remove()
        // https://en.cppreference.com/w/cpp/algorithm/remove
        {
            // remove()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };

                int num = 3; // Removed Value

                values.erase(std::remove(values.begin(), values.end(), num), values.end());
                // values: 1 2 4 5
            }

            // remove_if()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };

                auto pred = [](int num) { return num < 3; };

                values.erase(std::remove_if(values.begin(), values.end(), pred), values.end());
                // values: 3 4 5
            }
        }

        // remove_copy()
        // https://en.cppreference.com/w/cpp/algorithm/remove_copy
        {
            // remove_copy()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };
                vector<int> copied;

                int num = 3; // Removed Value

                std::remove_copy(values.begin(), values.end(), std::back_inserter(copied), num);
                // copied: 1 2 4 5
            }

            // remove_copy()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };
                vector<int> copied;

                auto pred = [](int num) { return num < 3; };

                std::remove_copy_if(values.begin(), values.end(), std::back_inserter(copied), pred);
                // copied: 3 4 5
            }

        }

        // replace()
        // https://en.cppreference.com/w/cpp/algorithm/replace
        {
            // replace()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };

                int oldNum = 3;
                int newNum = 7;

                std::replace(values.begin(), values.end(), oldNum, newNum);
                // values: 1 2 7 4 5
            }

            // replace_if()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };

                auto pred = [](int num) { return num % 2 == 0; };
                int newNum = 3;

                std::replace_if(values.begin(), values.end(), pred, newNum);
                // values: 1, 3, 3, 3, 5
            }
        }

        // replace_copy()
        // https://en.cppreference.com/w/cpp/algorithm/replace_copy
        {
            // replace_copy()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };
                vector<int> copied;

                int oldNum = 3;
                int newNum = 7;

                std::replace_copy(values.begin(), values.end(), std::back_inserter(copied), oldNum, newNum);
                // copied: 1 2 7 4 5
            }

            // replace_copy_if()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };
                vector<int> copied;

                auto pred = [](int num) { return num % 3 == 0; };
                int newNum = 3;

                std::replace_copy_if(values.begin(), values.end(), std::back_inserter(copied), pred, newNum);
                // copied: 1, 3, 3, 3, 5
            }
        }

        // reverse()
        // https://en.cppreference.com/w/cpp/algorithm/reverse
        {
            vector<int> values{ 1, 2, 3, 4, 5 };

            std::reverse(values.begin(), values.end());
            // values: 5 4 3 2 1
        }

        // reverse_copy()
        // https://en.cppreference.com/w/cpp/algorithm/reverse_copy
        {
            vector<int> values{ 1, 2, 3, 4, 5 };
            vector<int> copied;

            std::reverse_copy(values.begin(), values.end(), std::back_inserter(copied));
            // copied: 5 4 3 2 1
        }
    }

    // [Sorting operations]
    {
        // is_sorted()
        // https://en.cppreference.com/w/cpp/algorithm/is_sorted
        {
            vector<int> values{ 1, 2, 3, 4, 5 };

            bool isSorted = std::is_sorted(values.begin(), values.end());
            // true
        }

        // sort()
        // https://en.cppreference.com/w/cpp/algorithm/sort
        {
            // Ascending order 
            {
                vector<int> values{ 5, 4, 3, 2, 1 };

                std::sort(values.begin(), values.end());
                // values: 1 2 3 4 5
            }

            // Descending order
            {
                vector<int> values{ 1, 2, 3, 4, 5 };

                std::sort(values.begin(), values.end(), greater<int>());
                // values: 5 4 3 2 1
            }

            // Custom order
            {
                vector<pair<int, int>> values; // <x, y>
                values.push_back(make_pair(1, 3));
                values.push_back(make_pair(2, 2));
                values.push_back(make_pair(3, 1));

                auto pred = [](pair<int, int> a, pair<int, int> b) {
                    return a.second < b.second;
                };

                std::sort(values.begin(), values.end(), pred);
                // values: (3, 1) (2, 2) (1, 3)
            }
        }
    }

    // [Binary search operations]
    {
        // binary_search()
        // https://en.cppreference.com/w/cpp/algorithm/binary_search
        {
            vector<int> values{ 1, 2, 3, 4, 5 };

            int num = 3;

            bool result = std::binary_search(values.begin(), values.end(), num);
            // result: true
        }
    }

    // [Minimum/maximum operations]
    {
        // max()
        // https://en.cppreference.com/w/cpp/algorithm/max
        {
            int result = std::numeric_limits<int>::min();
            int num = 3;

            result = std::max(result, num);
            // result: 3
        }

        // max_element()
        // https://en.cppreference.com/w/cpp/algorithm/max_element
        {
            vector<int> values{ -2, -1, 0, 1, 2 };

            auto iterator1 = std::max_element(values.begin(), values.end());
            int index1 = std::distance(values.begin(), iterator1);
            // *iter1: 2, index1: 4

            auto pred = [](const int a, const int b)
            {
                return std::abs(a) < std::abs(b); // #includede <cmath>
            };

            auto iterator2 = std::max_element(values.begin(), values.end(), pred);
            int index2 = std::distance(values.begin(), iterator2);
            // *iter2: -2, index2: 0
        }

        // min()
        // https://en.cppreference.com/w/cpp/algorithm/min
        {
            int result = std::numeric_limits<int>::max();
            int num = 3;

            result = std::min(result, num);
            // result: 3
        }

        // min_element()
        // https://en.cppreference.com/w/cpp/algorithm/min_element
        {
            vector<int> values{ -2, -1, 0, 1, 2 };

            auto iter1 = std::min_element(values.begin(), values.end());
            int index1 = std::distance(values.begin(), iter1);
            // *iter1: -2, index1: 0

            auto pred = [](const int a, const int b)
            {
                return std::abs(a) < std::abs(b); // #includede <cmath>
            };

            auto iter2 = std::min_element(values.begin(), values.end(), pred);
            int index2 = std::distance(values.begin(), iter2);
            // *iter2: 0, index2: 2
        }

        // minmax()
        // https://en.cppreference.com/w/cpp/algorithm/minmax
        {
            auto result = std::minmax({ 1, 2, 3, 4, 5 });
            // result.first: 1 (MIN)
            // result.first: 5 (MAX)
        }

        // minmax()
        // https://en.cppreference.com/w/cpp/algorithm/minmax
        {
            vector<int> values{ 1, 2, 3, 4, 5 };

            auto result = std::minmax_element(values.begin(), values.end());
            // *result.first: 1 (MIN)
            // *result.second: 5 (MAX)

            int indexOfMin = std::distance(values.begin(), result.first);
            int indexOfMax = std::distance(values.begin(), result.second);
            // indexOfMin : 0, indexOfMin : 4
        }
    }

    // [Comparison operations]
    {
        // equal()
        // https://en.cppreference.com/w/cpp/algorithm/equal
        {
            // equal()
            {
                vector<int> values{ 1, 2, 3, 4, 5 };
                vector<int> values2{ 1, 2, 3, 4, 5 };

                bool result = std::equal(values.begin(), values.end(), values2.begin());
                // result: true
            }

            // Palindrome
            {
                vector<int> values{ 1, 2, 3, 2, 1 };
                int size = values.size() / 2;

                bool result = std::equal(values.begin(), values.begin() + size, values.rbegin());
                // result: true
            }
        }
    }

    // [Permutation operations]
    {
        // is_permutation()
        // https://en.cppreference.com/w/cpp/algorithm/is_permutation
        {
            vector<int> values{ 1, 2, 3, 4, 5 };
            vector<int> values2{ 3, 5, 4, 1, 2 };

            bool result = std::is_permutation(values.begin(), values.end(), values2.begin());
            // result: true
        }

        // next_permutation()
        // https://en.cppreference.com/w/cpp/algorithm/next_permutation
        {
            vector<int> values{ 1, 2, 3 };

            std::sort(values.begin(), values.end());

            do
            {
                for (auto element : values)
                {
                    cout << element << ' ';
                }
                cout << '\n';
            } while (std::next_permutation(values.begin(), values.end()));

            // 1 2 3
            // 1 3 2
            // 2 1 3
            // 2 3 1
            // 3 1 2
            // 3 2 1
        }

        // prev_permutation()
        // https://en.cppreference.com/w/cpp/algorithm/prev_permutation
        {
            vector<int> value{ 1, 2, 3 };

            std::sort(value.begin(), value.end(), std::greater<char>());

            do
            {
                for (auto element : value)
                {
                    cout << element << ' ';
                }
                cout << '\n';
            } while (std::prev_permutation(value.begin(), value.end()));

            // 3 2 1
            // 3 1 2
            // 2 3 1
            // 2 1 3
            // 1 3 2
            // 1 2 3
        }
    }

    return 0;
}

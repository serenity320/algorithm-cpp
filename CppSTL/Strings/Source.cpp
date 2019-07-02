#include <cstdio>
#include <iostream>

#include <string>

using namespace std;

int main()
{
    // [std::basic_string]
    // https://en.cppreference.com/w/cpp/string/basic_string
    {
        // string  : basic_string<char>
        // wstring : basic_string<wchar_t>
        // u16string : basic_string<char16_t>
        // u32string : basic_string<char32_t>

        // [Input String]
        // http://www.cplusplus.com/doc/tutorial/basic_io/
        {
            string str;

            cin >> str; // 띄어쓰기 미포함
            getline(cin, str); // 띄어쓰기 포함

            cout << str << '\n';
            printf("%s\n", str.c_str());
        }

        // [Operations]
        {
            // at()
            // https://en.cppreference.com/w/cpp/string/basic_string/at
            {
                string str = "ABCDEFG";

                char ch = str.at(3);
                // ch: 'D'
            }

            // substr()
            // https://en.cppreference.com/w/cpp/string/basic_string/substr
            {
                string str = "ABCDEFG";
                string subStr = str.substr(2, 5); // Count
                // sub: "CDEFG"

                auto substring = [](string str, int start, int end)
                {
                    int index = (end - start) + 1;
                    string result = str.substr(start, index);

                    return result;
                };

                string subStr2 = substring(str, 2, 5); // Count
                // subStr2: "CDEF"
            }
        }

        // [Search]
        {
            // find()
            // https://en.cppreference.com/w/cpp/string/basic_string/find
            {
                string str = "ABCABC";
                string findStr = "C";

                auto result = str.find(findStr);

                if (result != std::string::npos)
                {
                    string subStr = str.substr(result);

                    printf("%s : %d", subStr.c_str(), result);
                    // CABC : 2
                }
            }

            // rfind()
            // https://en.cppreference.com/w/cpp/string/basic_string/rfind
            {
                string str = "ABCABC";
                string findStr = "C";

                auto result = str.rfind(findStr);

                if (result != std::string::npos)
                {
                    string subStr = str.substr(result);

                    printf("%s : %d", subStr.c_str(), result);
                    // CABC : 5
                }
            }
        }

        // [Numeric conversions]
        {
            // stoi()
            // https://en.cppreference.com/w/cpp/string/basic_string/stol
            {
                string str = "320";

                int num = std::stoi(str);
                // num: 320
            }

            // to_string()
            // https://en.cppreference.com/w/cpp/string/basic_string/to_string
            {
                int num = 320;

                string str = std::to_string(num);
                // str: "320"
            }
        }
    }

    return 0;
}

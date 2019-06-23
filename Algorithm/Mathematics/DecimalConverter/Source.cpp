#include <cstdio>
#include <string>

using namespace std;

const string HEX_STRING = "0123456789ABCDEF";

string ConvertDecToBase(int num, int base);
int ConvertBaseToDec(string num, int base);

int main()
{
    string base = ConvertDecToBase(30, 2); // 30 -> 2진수
    printf("%s\n", base.c_str());

    int dec = ConvertBaseToDec("24F", 16); // 24F -> 10진수
    printf("%d\n", dec);

    return 0;
}

string ConvertDecToBase(int num, int base)
{
    string result;
    int number = num;

    while (number != 0)
    {
        result += HEX_STRING[number % base]; // 나머지
        number /= base; // 몫
    }

    reverse(result.begin(), result.end());

    return result;
}

int ConvertBaseToDec(string str, int base)
{
    int result = 0;
    int multiple = 1;

    for (int i = str.size() - 1; i >= 0; --i)
    {
        int num = 0;

        if (str[i] >= '0' && str[i] <= '9')
        {
            num = str[i] - '0';
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            num = (str[i] - 'A') + 10;
        }

        result += num * multiple;
        multiple *= base;
    }

    return result;
}

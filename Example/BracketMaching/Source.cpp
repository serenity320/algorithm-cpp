#include <string>
#include <stack>

using namespace std;

int main()
{
    string brackets = "({[]})"; // YES
    //string brackets = "({[)}]"; // NO
    //string brackets = "({[)}"; // NO

    stack<char> stack;
    bool isValidation = true;

    for (size_t i = 0; i < brackets.length(); ++i)
    {
        if (brackets[i] == '[' || brackets[i] == '{' || brackets[i] == '(')
        {
            stack.push(brackets[i]);
        }
        else
        {
            if (stack.empty())
            {
                isValidation = false;
                break;
            }
            else
            {
                char ch = stack.top();

                if (brackets[i] == ']' && ch == '[')
                {
                    stack.pop();
                }
                else if (brackets[i] == '}' && ch == '{')
                {
                    stack.pop();
                }
                else if (brackets[i] == ')' && ch == '(')
                {
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
        }
    }

    if (!stack.empty() || !isValidation)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }

    return 0;
}

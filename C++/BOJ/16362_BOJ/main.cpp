#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int main()
{
    string input;
    getline(cin, input);
    bool isImproper = false;
    stack<char> st;

    // int parenthesis = 0;
    // for (int i = 0; i < input.length(); i++)
    // {
    //     if (input[i] == '(')
    //         parenthesis++;
    //     else if (input[i] == ')')
    //         parenthesis--;
    // }
    // if (parenthesis != 0)
    // {
    //     cout << "error";
    //     return 0;
    // }

    for (int i = 0; i < input.length(); i++)
    {
        while (i < input.length() && input[i] == ' ')
            i++;
        if (i >= input.length())
            break;

        if (input[i] == '(')
        {
            // (인 경우
            // error
            if (!st.empty() && st.top() == 'c')
            {
                cout << "error";
                return 0;
            }
            st.push(input[i]);
        }
        else if (isOperator(input[i]))
        {
            // 연산자인 경우
            // error
            if (!st.empty() && st.top() != 'c')
            {
                cout << "error";
                return 0;
            }
            st.push('o');
        }
        else if (input[i] == ')')
        {
            // )인 경우
            // error
            if (st.empty() || st.top() != 'c')
            {
                cout << "error";
                return 0;
            }
            st.pop();

            // improper
            bool isOperatorTurn = true;
            int cnt = 0;
            while (!st.empty())
            {
                if (isOperatorTurn)
                {
                    if (st.top() == 'o')
                    {
                        cnt++;
                    }
                    else if (st.top() == '(')
                    {
                        if (cnt != 1)
                            isImproper = true;
                        break;
                    }
                    else if (st.top() == 'c')
                    {
                        cout << "error";
                        return 0;
                    }
                    isOperatorTurn = false;
                }
                else
                {
                    if (st.top() != 'c')
                    {
                        cout << "error";
                        return 0;
                    }
                    isOperatorTurn = true;
                }
                st.pop();
            }
            st.pop();
            st.push('c');
        }
        else
        {
            // 피연산자인 경우
            // error
            if (!st.empty() && st.top() == 'c')
            {
                cout << "error";
                return 0;
            }
            st.push('c');
        }
    }

    if (isImproper)
    {
        cout << "improper";
        return 0;
    }

    bool isOperatorTurn = false;
    int cnt = 0;
    while (!st.empty())
    {
        if (isOperatorTurn)
        {
            if (st.top() != 'o')
            {
                cout << "error";
                return 0;
            }
            cnt++;
            st.pop();
            isOperatorTurn = false;
        }
        else
        {
            if (st.top() != 'c')
            {
                cout << "error";
                return 0;
            }
            st.pop();
            isOperatorTurn = true;
        }
    }

    if (cnt == 1)
        cout << "proper";
    else
        cout << "improper";

    return 0;
}
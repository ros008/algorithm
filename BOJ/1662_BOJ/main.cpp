#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int a = 1, b = 2;
    cout << a + b << "\n";

    string S;
    stack<string> stringStack;
    cout << "Dfdfd"
         << "\n";
    cin >> S;

    cout << "S : " << S;

    // for (int i = 0; i < S.length(); i++)
    // {
    //     if (S[i] == ')')
    //     {
    //         string tmp = "";
    //         while (stringStack.top() != "(")
    //         {
    //             tmp = stringStack.top() + tmp;
    //             stringStack.pop();
    //         }
    //         stringStack.pop();

    //         string res = "";
    //         int num = stoi(stringStack.top());
    //         stringStack.pop();
    //         for (int i = 0; num; i++)
    //             res += tmp;

    //         stringStack.push(res);
    //     }
    //     else if (S[i] == '(' || (S[i] >= '0' && S[i] <= '9'))
    //     {
    //         stringStack.push(S.substr(i, 1));
    //     }
    // }

    // string answer = "";

    // while (!stringStack.empty())
    // {
    //     answer = stringStack.top() + answer;
    //     stringStack.pop();
    // }

    // cout << answer;

    return 0;
}
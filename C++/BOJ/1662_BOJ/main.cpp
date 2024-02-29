#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string S;
    stack<pair<char, int>> stringStack;

    cin >> S;

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == ')')
        {
            int strSize = 0;
            while (stringStack.top().first != '(')
            {
                strSize += stringStack.top().second;
                stringStack.pop();
            }
            stringStack.pop();
            int repeatCnt = stringStack.top().first - '0';
            stringStack.top().second = repeatCnt * strSize;
            repeatCnt = 0;
        }
        else
        {
            stringStack.push({S[i], 1});
        }
    }

    int answer = 0;

    while (!stringStack.empty())
    {
        answer = stringStack.top().second + answer;
        stringStack.pop();
    }

    cout << answer;

    return 0;
}
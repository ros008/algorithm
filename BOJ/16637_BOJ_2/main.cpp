#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int N, result = INT_MIN;
string str;

int calculator(int a, int b, char oper)
{
    if (oper == '+')
        return a + b;
    else if (oper == '-')
        return a - b;
    else
        return a * b;
}

void solve(int pos, int cur)
{
    if (pos >= N)
    {
        result = max(result, cur);
        return;
    }
    char oper = (pos == 0) ? '+' : str[pos - 1];
    if (pos + 2 < str.length())
    {
        int parenthesis = calculator(str[pos] - '0', str[pos + 2] - '0', str[pos + 1]);
        solve(pos + 4, calculator(cur, parenthesis, oper));
    }
    solve(pos + 2, calculator(cur, str[pos] - '0', oper));
}

int main()
{
    cin >> N >> str;
    solve(0, 0);
    cout << result << "\n";
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int N;
bool flag = false;

bool isValidString(string str)
{
    for (int i = 1; i <= str.length() / 2; i++)
    {
        string a = str.substr(str.length() - 2 * i, i);
        string b = str.substr(str.length() - i, i);
        if (a.compare(b) == 0)
            return false;
    }
    return true;
}

void dfs(string str)
{
    if (flag)
        return;
    if (!isValidString(str))
        return;
    if (str.length() == N)
    {
        cout << str << "\n";
        flag = true;
        return;
    }
    dfs(str + "1");
    dfs(str + "2");
    dfs(str + "3");
}

int main()
{
    cin >> N;
    dfs("1");
    // isValidString("1212121");
    return 0;
}
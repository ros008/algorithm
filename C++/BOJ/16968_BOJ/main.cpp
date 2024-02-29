#include <iostream>
#include <vector>
#include <string>

using namespace std;

string numType;
int cnt = 0;

void findStr(int pos, string str)
{
    if (pos == numType.length())
    {
        cnt++;
        return;
    }

    if (numType[pos] == 'c')
    {
        for (int i = 0; i < 26; i++)
        {
            char tmp = 'a' + i;
            if (str[str.length() - 1] != tmp)
            {
                str.push_back(tmp);
                findStr(pos + 1, str);
                str.pop_back();
            }
        }
    }
    else if (numType[pos] == 'd')
    {
        for (int i = 0; i < 10; i++)
        {
            char tmp = '0' + i;
            if (str[str.length() - 1] != tmp)
            {
                str.push_back(tmp);
                findStr(pos + 1, str);
                str.pop_back();
            }
        }
    }
}

int main()
{
    cin >> numType;
    findStr(0, "");
    cout << cnt << "\n";
    return 0;
}
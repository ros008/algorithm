#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string s)
{
    int answer = 0;
    string strAns = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            strAns += s[i];
            continue;
        }

        if (s[i] == 'z')
        {
            // 0
            strAns += '0';
            i += 3;
        }
        else if (s[i] == 'o')
        {
            // 1
            strAns += '1';
            i += 2;
        }
        else if (s[i] == 't')
        {
            // 2 3
            if (s.substr(i, 3) == "two")
            {
                strAns += '2';
                i += 2;
            }
            else
            {
                strAns += '3';
                i += 4;
            }
        }
        else if (s[i] == 'f')
        {
            // 4 5
            if (s.substr(i, 4) == "four")
            {
                strAns += '4';
                i += 3;
            }
            else
            {
                strAns += '5';
                i += 3;
            }
        }
        else if (s[i] == 's')
        {
            // 6 7
            if (s.substr(i, 3) == "six")
            {
                strAns += '6';
                i += 2;
            }
            else
            {
                strAns += '7';
                i += 4;
            }
        }
        else if (s[i] == 'e')
        {
            // 8
            strAns += '8';
            i += 4;
        }
        else if (s[i] == 'n')
        {
            // 9
            strAns += '9';
            i += 3;
        }
    }
    answer = stoi(strAns);
    return answer;
}

int main()
{
    string s = "one4seveneight";

    cout << solution(s);

    return 0;
}
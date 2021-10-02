#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        string p;
        cin >> p;
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        deque<int> dq;
        string tmp;
        for (int i = 0; i < arr.length(); i++)
        {
            if (arr[i] == '[')
            {
                continue;
            }
            else if (arr[i] >= '0' && arr[i] <= '9')
            {
                tmp += arr[i];
            }
            else if (arr[i] == ',' || arr[i] == ']')
            {
                if (tmp.length() != 0)
                {
                    dq.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }
        bool left = true;
        bool isError = false;
        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == 'R')
            {
                left = !left;
            }
            else if (p[i] == 'D')
            {
                if (dq.empty())
                {
                    isError = true;
                    break;
                }
                if (left)
                {
                    dq.pop_front();
                }
                else
                {
                    dq.pop_back();
                }
            }
        }
        if (isError)
            cout << "error\n";
        else
        {
            if (left)
            {
                cout << "[";
                while (!dq.empty())
                {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty())
                        cout << ",";
                }
                cout << "]\n";
            }
            else
            {
                cout << "[";
                while (!dq.empty())
                {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty())
                        cout << ",";
                }
                cout << "]\n";
            }
        }
    }

    return 0;
}
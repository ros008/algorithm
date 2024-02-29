#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    deque<int> dq;
    int commandCnt, num;
    cin >> commandCnt;

    for (int i = 0; i < commandCnt; i++)
    {
        string command;
        cin >> command;

        if (command == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if (command.compare("push_back") == 0)
        {
            cin >> num;
            dq.push_back(num);
        }
        else if (command.compare("pop_front") == 0)
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
            {
                num = dq.front();
                cout << num << "\n";
                dq.pop_front();
            }
        }
        else if (command.compare("pop_back") == 0)
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
            {
                num = dq.back();
                cout << num << "\n";
                dq.pop_back();
            }
        }
        else if (command.compare("size") == 0)
        {
            cout << dq.size() << "\n";
        }
        else if (command.compare("empty") == 0)
        {
            if (dq.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (command.compare("front") == 0)
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
                cout << dq.front() << "\n";
        }
        else if (command.compare("back") == 0)
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
                cout << dq.back() << "\n";
        }
    }

    return 0;
}
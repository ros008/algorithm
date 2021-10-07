#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int M;
    char command;

    cin >> s;
    cin >> M;

    list<char> str(s.begin(), s.end());
    auto cursor = str.end();

    for (int i = 0; i < M; i++)
    {
        char command;
        cin >> command;
        if (command == 'L' && cursor != str.begin())
            cursor--;
        else if (command == 'D' && cursor != str.end())
            cursor++;
        else if (command == 'B' && cursor != str.begin())
            cursor = str.erase(--cursor);
        else if (command == 'P')
        {
            char input;
            cin >> input;
            str.insert(cursor, input);
        }
    }

    for (auto i = str.begin(); i != str.end(); i++)
        cout << *i;

    return 0;
}
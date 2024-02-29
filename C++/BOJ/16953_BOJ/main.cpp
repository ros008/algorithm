#include <iostream>
#include <queue>

using namespace std;

const int MAX_INT = 1000000000;

int A, B;

void bfs()
{
    bool flag = false;
    queue<pair<int, int>> q;
    q.push({A, 1});

    while (!q.empty())
    {
        int cur_num = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        if (cur_num == B)
        {
            cout << cur_cnt;
            flag = true;
            break;
        }
        if (cur_num * 2 <= B)
        {
            q.push({cur_num * 2, cur_cnt + 1});
        }
        if (cur_num <= MAX_INT / 10 && cur_num * 10 + 1 <= B)
        {
            q.push({cur_num * 10 + 1, cur_cnt + 1});
        }
    }
    if (!flag)
        cout << -1;
}

int main()
{
    cin >> A >> B;
    bfs();
    return 0;
}
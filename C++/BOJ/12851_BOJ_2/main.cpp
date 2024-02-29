#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

int N, K;
int min_time = 0, min_cnt = 0;
bool visited[MAX + 1];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({N, 0});

    while (!q.empty())
    {
        int cur_loc = q.front().first;
        int cur_time = q.front().second;
        visited[cur_loc] = true;
        q.pop();

        if (min_time && min_time == cur_time && cur_loc == K)
        {
            min_cnt++;
            continue;
        }
        if (!min_time && cur_loc == K)
        {
            min_cnt++;
            min_time = cur_time;
            continue;
        }

        if (cur_loc + 1 <= MAX && !visited[cur_loc + 1])
        {
            q.push({cur_loc + 1, cur_time + 1});
        }
        if (cur_loc - 1 >= 0 && !visited[cur_loc - 1])
        {
            q.push({cur_loc - 1, cur_time + 1});
        }
        if (cur_loc * 2 <= MAX && !visited[cur_loc * 2])
        {
            q.push({cur_loc * 2, cur_time + 1});
        }
    }
}

int main()
{
    cin >> N >> K;
    bfs();
    cout << min_time << " " << min_cnt;

    return 0;
}
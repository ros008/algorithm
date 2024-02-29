#include <iostream>
#include <queue>

using namespace std;

const int MAX_LEN = 100000;

int N, K;
int min_cnt = 0;
int min_time = 0;
bool visited[MAX_LEN + 1];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({N, 0});

    while (!q.empty())
    {
        int cur_loc = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        visited[cur_loc] = true;

        // 처음으로 K에 도달한 경우
        if (!min_cnt && cur_loc == K)
        {
            min_time = cur_time;
            min_cnt++;
            continue;
        }

        // K에 도달한 적이 있는 상태에서 K에 또 도달한 경우
        if (min_cnt && cur_loc == K && min_time == cur_time)
        {
            min_cnt++;
            continue;
        }

        if (cur_loc + 1 <= MAX_LEN && !visited[cur_loc + 1])
            q.push({cur_loc + 1, cur_time + 1});
        if (cur_loc - 1 >= 0 && !visited[cur_loc - 1])
            q.push({cur_loc - 1, cur_time + 1});
        if (cur_loc * 2 <= MAX_LEN && !visited[cur_loc * 2])
            q.push({cur_loc * 2, cur_time + 1});
    }
}

int main()
{
    cin >> N >> K;
    bfs();
    cout << min_time << " " << min_cnt;
    return 0;
}
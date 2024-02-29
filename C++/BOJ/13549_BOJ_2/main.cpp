#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000;

int N, K;
int cost[MAX + 1];

int dijkstra(int start)
{
    for (int i = 0; i <= MAX; i++)
        cost[i] = MAX;
    cost[N] = 0;

    priority_queue<pair<int, int>> q;
    q.push({0, N});

    while (!q.empty())
    {
        int cur_loc = q.top().second;
        int cur_sec = -q.top().first;
        q.pop();

        if (cost[cur_loc] < cur_sec)
            continue;

        int next_loc, next_sec;

        next_loc = cur_loc * 2, next_sec = cur_sec;
        if (next_loc <= MAX && next_sec < cost[next_loc])
        {
            q.push({-next_sec, next_loc});
            cost[next_loc] = next_sec;
        }

        next_loc = cur_loc + 1, next_sec = cur_sec + 1;
        if (next_loc <= MAX && next_sec < cost[next_loc])
        {
            q.push({-next_sec, next_loc});
            cost[next_loc] = next_sec;
        }

        next_loc = cur_loc - 1, next_sec = cur_sec + 1;
        if (next_loc >= 0 && next_sec < cost[next_loc])
        {
            q.push({-next_sec, next_loc});
            cost[next_loc] = next_sec;
        }
    }
    return cost[K];
}

int main()
{
    cin >> N >> K;

    cout << dijkstra(N);

    return 0;
}
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
    cost[start] = 0;

    priority_queue<pair<int, int>> q;
    q.push({0, start});

    while (!q.empty())
    {
        int cur_loc = q.top().second;
        int cur_cost = -q.top().first;
        q.pop();

        if (cost[cur_loc] < cur_cost)
            continue;

        if (cur_loc * 2 <= MAX && cur_cost < cost[cur_loc * 2])
        {
            cost[cur_loc * 2] = cur_cost;
            q.push({-cur_cost, cur_loc * 2});
        }

        if (cur_loc - 1 >= 0 && cur_cost + 1 < cost[cur_loc - 1])
        {
            cost[cur_loc - 1] = cur_cost + 1;
            q.push({-(cur_cost + 1), cur_loc - 1});
        }

        if (cur_loc + 1 <= MAX && cur_cost + 1 < cost[cur_loc + 1])
        {
            cost[cur_loc + 1] = cur_cost + 1;
            q.push({-(cur_cost + 1), cur_loc + 1});
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
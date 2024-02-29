#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<pair<int, int>> *connected, int v, int k)
{
    bool visited[5001] = {false};
    int cnt = 0;
    visited[v] = true;
    queue<pair<int, int>> q;
    for (int i = 0; i < connected[v].size(); i++)
    {
        q.push({connected[v][i].first, connected[v][i].second});
        visited[connected[v][i].first] = true;
    }
    while (!q.empty())
    {
        int cur = q.front().first;
        int curMinDist = q.front().second;
        q.pop();
        if (curMinDist >= k)
        {
            cnt++;
            for (int i = 0; i < connected[cur].size(); i++)
            {

                if (!visited[connected[cur][i].first])
                {
                    int dist = min(curMinDist, connected[cur][i].second);
                    q.push({connected[cur][i].first, dist});
                    visited[connected[cur][i].first] = true;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> connected[5001];

    for (int i = 0; i < N - 1; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        connected[p].push_back({q, r});
        connected[q].push_back({p, r});
    }
    for (int i = 0; i < Q; i++)
    {
        int k, v;
        cin >> k >> v;
        cout << bfs(connected, v, k) << "\n";
    }
}
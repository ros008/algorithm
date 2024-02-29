#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    vector<vector<int>> connected(n + 1);
    for (int i = 0; i < edge.size(); i++)
    {
        connected[edge[i][0]].push_back(edge[i][1]);
        connected[edge[i][1]].push_back(edge[i][0]);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        int cur_dist = dist[cur];
        q.pop();
        for (int i = 0; i < connected[cur].size(); i++)
        {
            int next = connected[cur][i];
            if (dist[next] == -1)
            {
                dist[next] = cur_dist + 1;
                q.push(next);
            }
        }
    }

    int max_len = *max_element(dist.begin(), dist.end());
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == max_len)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << solution(n, edge);

    return 0;
}
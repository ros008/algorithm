#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_V = 1001;

int N, M, V;
bool visited[MAX_V];
vector<int> adj[MAX_V];

void DFSRecursion(int idx)
{
    visited[idx] = true;
    cout << idx << " ";

    for (int i = 0; i < adj[idx].size(); i++)
    {
        int next = adj[idx][i];
        if (!visited[next])
            DFSRecursion(next);
    }
}

void DFSStack(int idx)
{
    stack<int> s;
    s.push(idx);
    visited[idx] = true;
    cout << idx << " ";

    while (!s.empty())
    {
        int cur = s.top();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (!visited[next])
            {
                s.push(next);
                visited[next] = true;
                cout << next << " ";
            }
            else if (i == adj[cur].size() - 1)
            {
                s.pop();
            }
        }
    }
}

void BFS(int idx)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(idx);
    visited[idx] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    DFSRecursion(V);
    cout << "\n";
    BFS(V);
    return 0;
}
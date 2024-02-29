#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 101;

int adj[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];

int computer, vertex;

void bfs()
{
    int cnt = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= computer; i++)
        {
            if (adj[cur][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main()
{
    cin >> computer >> vertex;
    for (int i = 0; i < vertex; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    bfs();

    return 0;
}
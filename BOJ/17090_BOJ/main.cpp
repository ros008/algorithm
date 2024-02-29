#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, ans = 0;
char maze[500 + 1][500 + 1];
queue<pair<int, int>> q;
bool visited[500 + 1][500 + 1];

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x - 1 >= 0 && maze[x - 1][y] == 'D' && !visited[x - 1][y])
        {
            q.push({x - 1, y});
            visited[x - 1][y] = true;
            ans++;
        }
        if (x + 1 < N && maze[x + 1][y] == 'U' && !visited[x + 1][y])
        {
            q.push({x + 1, y});
            visited[x + 1][y] = true;
            ans++;
        }
        if (y - 1 >= 0 && maze[x][y - 1] == 'R' && !visited[x][y - 1])
        {
            q.push({x, y - 1});
            visited[x][y - 1] = true;
            ans++;
        }
        if (y + 1 < M && maze[x][y + 1] == 'L' && !visited[x][y + 1])
        {
            q.push({x, y + 1});
            visited[x][y + 1] = true;
            ans++;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> maze[i][j];
            if ((i == 0 && maze[i][j] == 'U') ||
                (i == N - 1 && maze[i][j] == 'D') ||
                (j == 0 && maze[i][j] == 'L') ||
                (j == M - 1 && maze[i][j] == 'R'))
            {
                q.push({i, j});
                visited[i][j] = true;
                ans++;
            }
        }
    }
    bfs();
    cout << ans << "\n";

    return 0;
}
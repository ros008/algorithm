#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 100

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int R, C;
int map[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int time = 0, result = 0;

bool bfs()
{
    queue<pair<int, int>> q;
    int cnt = 0;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny])
                continue;
            if (map[nx][ny] == 0)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
            else
            {
                map[nx][ny] = 0;
                cnt++;
                visited[nx][ny] = true;
            }
        }
    }

    if (cnt == 0)
    {
        cout << time << "\n"
             << result << "\n";
        return true;
    }
    else
    {
        time++;
        result = cnt;
        return false;
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }

    while (true)
    {
        if (bfs())
            break;
        memset(visited, false, sizeof(visited));
    }

    return 0;
}
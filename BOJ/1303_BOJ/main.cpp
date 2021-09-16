#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_SIZE = 101;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M;
char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int white_team = 0, blue_team = 0;

int bfs(int x, int y)
{
    int cnt = 1;
    char cur_team = map[x][y];
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny] || map[nx][ny] != cur_team)
                continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
            cnt++;
        }
    }
    return cnt * cnt;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char input;
            cin >> input;
            map[i][j] = input;
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                int score = bfs(i, j);
                if (map[i][j] == 'B')
                    blue_team += score;
                else
                    white_team += score;
            }
        }
    }

    cout << white_team << " " << blue_team;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int N, M;
char map[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1][2];

int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int w = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1)
            return dist[x][y][w];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (map[nx][ny] == '0' && dist[nx][ny][w] == 0)
            {
                q.push({{nx, ny}, w});
                dist[nx][ny][w] = dist[x][y][w] + 1;
            }
            else if (map[nx][ny] == '1' && w == 0)
            {
                q.push({{nx, ny}, w + 1});
                dist[nx][ny][w + 1] = dist[x][y][w] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    cout << bfs();
    return 0;
}
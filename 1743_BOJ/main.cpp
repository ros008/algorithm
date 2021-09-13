#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 101;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int N, M, K;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int max_food_size = 0;

int bfs(int x, int y)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    cnt++;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 0 || visited[nx][ny])
                continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x - 1][y - 1] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                int cnt = bfs(i, j);
                if (cnt > max_food_size)
                    max_food_size = cnt;
            }
        }
    }

    cout << max_food_size;

    return 0;
}
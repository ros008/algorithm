#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int M, N, K;
int map[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
vector<int> answer;

int bfs(int m, int n)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({m, n});
    visited[m][n] = true;
    cnt++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || map[nx][ny] == 1 || visited[nx][ny])
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
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        for (int i = sy; i < ey; i++)
        {
            for (int j = sx; j < ex; j++)
            {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 0 && !visited[i][j])
            {
                int cnt = bfs(i, j);
                answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (auto i = answer.begin(); i != answer.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}
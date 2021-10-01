#include <iostream>
#include <vector>
#include <queue>

#define MAX 25

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int N;
char m[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];

int bfs(int a, int b)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (m[nx][ny] == '1' && !visited[nx][ny])
            {
                q.push({nx, ny});
                visited[ny][ny] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char input;
            cin >> input;
            m[i][j] = input;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         if (m[i][j] == '1' && !visited[i][j])
    //         {
    //             cout << bfs(i, j);
    //         }
    //     }
    // }

    return 0;
}
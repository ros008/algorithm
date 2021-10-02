#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 25

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int N;
char m[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1] = {
    0,
};
vector<int> answer;

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
                visited[nx][ny] = true;
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
            if (m[i][j] == '1' && !visited[i][j])
            {
                int cnt = bfs(i, j);
                answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << "\n";

    return 0;
}
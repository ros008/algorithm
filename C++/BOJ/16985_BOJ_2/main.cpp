#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;

int dh[] = {1, 0, 0, -1, 0, 0};
int dx[] = {0, 1, 0, 0, -1, 0};
int dy[] = {0, 0, 1, 0, 0, -1};

const int n = 5;
int ans = INF;
vector<vector<vector<int>>> cube(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
vector<vector<vector<int>>> cubeCopied(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
bool visited[n + 1][n + 1][n + 1];

void bfs()
{
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 0}});
    visited[0][0][0] = true;

    while (!q.empty())
    {
        int dist = q.front().first.first;
        int curH = q.front().first.second;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();

        if (curH == n - 1 && curX == n - 1 && curY == n - 1)
        {
            ans = min(ans, dist);
            return;
        }

        for (int i = 0; i < 6; i++)
        {
            int nh = curH + dh[i];
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nh < 0 || nh >= n || nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (cubeCopied[nh][nx][ny] == 1 && !visited[nh][nx][ny])
            {
                q.push({{dist + 1, nh}, {nx, ny}});
                visited[nh][nx][ny] = true;
            }
        }
    }
}

void rotateCube(int idx)
{
    vector<vector<int>> tmp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp[i][j] = cubeCopied[idx][n - 1 - j][i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cubeCopied[idx][i][j] = tmp[i][j];
        }
    }
}

void solve()
{
    for (int a = 0; a < 4; a++)
    {
        rotateCube(0);
        if (cubeCopied[0][0][0] != 1)
            continue;
        for (int b = 0; b < 4; b++)
        {
            rotateCube(1);
            for (int c = 0; c < 4; c++)
            {
                rotateCube(2);
                for (int d = 0; d < 4; d++)
                {
                    rotateCube(3);
                    for (int e = 0; e < 4; e++)
                    {
                        rotateCube(4);
                        if (cubeCopied[4][4][4] == 1)
                        {
                            bfs();
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    for (int h = 0; h < n; h++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cube[h][i][j];
            }
        }
    }
    vector<int> order;
    for (int i = 0; i < n; i++)
    {
        order.push_back(i);
    }

    do
    {
        for (int i = 0; i < n; i++)
        {
            cubeCopied[order[i]] = cube[i];
        }
        solve();
    } while (next_permutation(order.begin(), order.end()));

    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;
}
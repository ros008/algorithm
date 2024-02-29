#include <iostream>
#include <queue>
#include <vector>

#define MAX 100

using namespace std;

int dh[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, 0, -1, 0};
int dy[] = {0, 0, 0, -1, 0, 1};

int M, N, H;
int cnt = 0;
int box[MAX + 1][MAX + 1][MAX + 1];
queue<pair<int, pair<int, int>>> q;

bool isTotatoRipe()
{
    bool answer = true;
    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (box[h][i][j] == 0)
                {
                    answer = false;
                    break;
                }
            }
            if (!answer)
                break;
        }
        if (!answer)
            break;
    }
    return answer;
}

void bfs()
{
    while (!q.empty())
    {
        int qSize = q.size();
        cnt++;
        for (int i = 0; i < qSize; i++)
        {
            int curH = q.front().first;
            int curX = q.front().second.first;
            int curY = q.front().second.second;
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                int nextH = curH + dh[i];
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if (nextH < 0 || nextH >= H || nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                    continue;

                if (box[nextH][nextX][nextY] == 0)
                {
                    q.push({nextH, {nextX, nextY}});
                    box[nextH][nextX][nextY] = 1;
                }
            }
        }
    }

    if (isTotatoRipe())
        cout << cnt - 1 << "\n";
    else
        cout << -1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> box[h][i][j];
                if (box[h][i][j] == 1)
                {
                    q.push({h, {i, j}});
                }
            }
        }
    }
    bfs();

    return 0;
}
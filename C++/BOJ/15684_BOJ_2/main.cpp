#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, M, H, ans = INF;
bool isConnected[30 + 5][10 + 5];

bool findItoI()
{
    for (int i = 1; i <= N; i++)
    {
        int cur = i;
        for (int j = 1; j <= H; j++)
        {
            if (isConnected[j][cur])
            {
                cur++;
            }
            else if (isConnected[j][cur - 1])
            {
                cur--;
            }
        }
        if (i != cur)
            return false;
    }
    return true;
}

void selectLine(int idx, int cnt)
{
    if (cnt > 3)
        return;
    if (findItoI())
    {
        ans = min(ans, cnt);
        return;
    }

    for (int i = idx; i <= H; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (isConnected[i][j] || isConnected[i][j - 1] || isConnected[i][j + 1])
                continue;
            isConnected[i][j] = true;
            selectLine(i, cnt + 1);
            isConnected[i][j] = false;
        }
    }
}

int main()
{
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        isConnected[a][b] = true;
    }

    selectLine(1, 0);

    cout << ((ans == INF) ? -1 : ans) << "\n";

    return 0;
}
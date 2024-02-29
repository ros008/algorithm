#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

const int n = 10;
int map[n + 1][n + 1];
int paperCnt[6] = {0, 5, 5, 5, 5, 5};
int ans = INF;

bool isAllZero()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool canPutPaper(int x, int y, int size)
{
    if (x + size > n + 1 || y + size > n + 1)
        return false;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (map[i][j] == 0)
                return false;
        }
    }
    return true;
}

void putPaper(int x, int y, int size, int value)
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            map[i][j] = value;
        }
    }
}

pair<int, int> findPos()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 1)
            {
                return {i, j};
            }
        }
    }
}

void dfs(int cnt)
{
    if (isAllZero())
    {
        ans = min(ans, cnt);
        return;
    }

    pair<int, int> pos = findPos();
    for (int i = 5; i >= 1; i--)
    {
        if (paperCnt[i] == 0)
            continue;
        if (canPutPaper(pos.first, pos.second, i))
        {
            paperCnt[i]--;
            putPaper(pos.first, pos.second, i, 0);
            dfs(cnt + 1);
            putPaper(pos.first, pos.second, i, 1);
            paperCnt[i]++;
        }
    }
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0);

    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define INF 987654321

using namespace std;

int N, ans = INF;
int population[11];
bool isConnected[11][11];
bool isSelected[11];
bool visited[11];

bool checkConnection(vector<int> v, bool flag)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(v[0]);
    visited[v[0]] = true;
    int cnt = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (isConnected[cur][i] && isSelected[i] == flag && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
    if (v.size() == cnt)
        return true;
    return false;
}

bool checkValidity()
{
    vector<int> A, B;
    for (int i = 1; i <= N; i++)
    {
        if (isSelected[i])
            A.push_back(i);
        else
            B.push_back(i);
    }
    // 구역의 크기가 0이지 않는지
    if (A.size() == 0 || B.size() == 0)
        return false;
    // 두 구역이 각각 연결되어 있는지
    if (!checkConnection(A, true))
        return false;
    if (!checkConnection(B, false))
        return false;
    return true;
}

void caculateDiff()
{
    int cntA = 0, cntB = 0, diff;
    for (int i = 1; i <= N; i++)
    {
        if (isSelected[i])
            cntA += population[i];
        else
            cntB += population[i];
    }
    diff = abs(cntA - cntB);
    if (ans > diff)
        ans = diff;
}

void dfs(int idx, int cnt)
{
    if (cnt >= 1)
    {
        if (checkValidity())
        {
            caculateDiff();
        }
    }
    for (int i = idx; i <= N; i++)
    {
        if (!isSelected[i])
        {
            isSelected[i] = true;
            dfs(i, cnt + 1);
            isSelected[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> population[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int dest;
            cin >> dest;
            isConnected[i][dest] = true;
            isConnected[dest][i] = true;
        }
    }

    dfs(1, 0);

    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;
}
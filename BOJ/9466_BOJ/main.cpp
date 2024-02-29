#include <iostream>
#include <cstring>

#define MAX 100000

using namespace std;

int n, cnt = 0;
int connect[MAX + 1];
bool visited[MAX + 1];
bool done[MAX + 1];

void dfs(int cur)
{
    visited[cur] = true;
    int next = connect[cur];
    if (!visited[next])
    {
        dfs(next);
    }
    else
    {
        if (!done[next])
        {
            for (int i = next; i != cur; i = connect[i])
            {
                cnt++;
            }
            cnt++;
        }
    }
    done[cur] = true;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> connect[i];
            visited[i] = false;
            done[i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
        }
        // cout << "answer: " << n << " " << cnt << " " << n - cnt << "\n";
        cout << n - cnt << "\n";
    }

    return 0;
}
#include <iostream>
#include <queue>

#define MAX 100000

using namespace std;

int N, K;
bool visited[MAX + 10];
int parent[MAX + 10];
vector<int> path;

void bfs(int pos)
{
    queue<pair<int, int>> q;
    q.push({0, pos});
    visited[pos] = true;

    while (!q.empty())
    {
        int sec = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (cur == K)
        {
            cout << sec << "\n";
            int idx = K;
            while (idx != N)
            {
                path.push_back(idx);
                idx = parent[idx];
            }
            path.push_back(N);
        }

        int loc_1 = cur - 1, loc_2 = cur + 1, loc_3 = cur * 2;
        if (loc_1 >= 0 && !visited[loc_1])
        {
            q.push({sec + 1, loc_1});
            visited[loc_1] = true;
            parent[loc_1] = cur;
        }

        if (loc_2 <= MAX && !visited[loc_2])
        {
            q.push({sec + 1, loc_2});
            visited[loc_2] = true;
            parent[loc_2] = cur;
        }

        if (loc_3 <= MAX && !visited[loc_3])
        {
            q.push({sec + 1, loc_3});
            visited[loc_3] = true;
            parent[loc_3] = cur;
        }
    }
}

int main()
{
    cin >> N >> K;
    bfs(N);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    return 0;
}
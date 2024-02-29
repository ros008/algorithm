#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

int N, K;
int min_time;
bool visited[MAX + 1];

int bfs()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, N});

    while (!q.empty())
    {
        int cur_loc = q.top().second;
        int cur_sec = q.top().first;
        q.pop();
        visited[cur_loc] = true;
        if (cur_loc == K)
            return cur_sec;

        if (cur_loc * 2 <= MAX && !visited[cur_loc * 2])
        {
            q.push({cur_sec, cur_loc * 2});
            visited[cur_loc * 2] = true;
        }
        if (cur_loc + 1 <= MAX && !visited[cur_loc + 1])
        {
            q.push({cur_sec + 1, cur_loc + 1});
            visited[cur_loc + 1] = true;
        }
        if (cur_loc - 1 >= 0 && !visited[cur_loc - 1])
        {
            q.push({cur_sec + 1, cur_loc - 1});
            visited[cur_loc - 1] = true;
        }
    }
}

int main()
{
    cin >> N >> K;
    cout << bfs();

    return 0;
}
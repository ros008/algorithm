#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000

using namespace std;

int N, K;
bool visited[MAX + 10];

int bfs(int pos)
{
    int answer = 0;
    queue<pair<int, int>> q;
    q.push({0, pos});
    visited[pos] = true;

    while (!q.empty())
    {
        int cur = q.front().second;
        int sec = q.front().first;
        q.pop();

        if (cur == K)
        {
            answer = sec;
            break;
        }

        if (cur + 1 <= K && !visited[cur + 1])
        {
            q.push({sec + 1, cur + 1});
            visited[cur + 1] = true;
        }

        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            q.push({sec + 1, cur - 1});
            visited[cur - 1] = true;
        }

        if (cur * 2 <= MAX + 1 && !visited[cur * 2])
        {
            q.push({sec + 1, cur * 2});
            visited[cur * 2] = true;
        }
    }
    return answer;
}

int main()
{
    cin >> N >> K;
    cout << bfs(N);

    return 0;
}
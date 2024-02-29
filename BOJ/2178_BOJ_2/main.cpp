#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 101;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int N, M;
char map[MAX_SIZE][MAX_SIZE];
int cnt_map[MAX_SIZE][MAX_SIZE] = {0};
bool visited[MAX_SIZE][MAX_SIZE];

// 전체 탐색 후 map[N-1][M-1] 찾는 것과
// pair<pair<int,int>, int> 로 찾다가 d return 하는 것 중에
// 어떤 방식이 더 빠른지, 왜 빠른지 생각해보기

void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    cnt_map[0][0] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || map[nx][ny] == '0')
                continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
            cnt_map[nx][ny] = cnt_map[cur.first][cur.second] + 1;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    bfs();

    cout << cnt_map[N - 1][M - 1];

    return 0;
}
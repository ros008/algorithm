#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<int> card;
vector<vector<int>> board2;
int r2, c2;

int bfs(int dest)
{
    bool visited[4][4] = {
        0,
    };
    queue<pair<pair<int, int>, int>> q;
    q.push({{r2, c2}, 0});
    visited[r2][c2] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if (board2[x][y] == dest)
        {
            board2[x][y] = 0;
            r2 = x, c2 = y;
            return cnt + 1;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
                continue;
            if (!visited[nx][ny])
            {
                q.push({{nx, ny}, cnt + 1});
                visited[nx][ny] = true;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x;
            int ny = y;
            while (nx + dx[i] >= 0 && nx + dx[i] < 4 && ny + dy[i] >= 0 && ny + dy[i] < 4)
            {
                nx += dx[i];
                ny += dy[i];
                if (board2[nx][ny])
                    break;
            }
            if (!visited[nx][ny])
            {
                q.push({{nx, ny}, cnt + 1});
                visited[nx][ny] = true;
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c)
{
    int answer = 0;
    answer = 0x3f3f3f3f;
    bool cardList[7] = {
        0,
    };
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] != 0)
                cardList[board[i][j]] = true;
    for (int i = 1; i <= 6; i++)
        if (cardList[i])
            card.push_back(i);

    do
    {
        board2 = board;
        r2 = r;
        c2 = c;
        int result = 0;

        for (int i = 0; i < card.size(); i++)
        {
            result += bfs(card[i]);
            result += bfs(card[i]);
        }
        answer = min(answer, result);

    } while (next_permutation(card.begin(), card.end()));

    return answer;
}

int main()
{
    vector<vector<int>> board = {{1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0}};
    int r = 1, c = 0;

    cout << solution(board, r, c);

    return 0;
}
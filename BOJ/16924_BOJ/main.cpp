#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, maxSize;
char map[101][101];
bool visited[101][101];
vector<pair<pair<int, int>, int>> answer;

void findCross(int x, int y)
{
    for (int crossSize = 1; crossSize <= maxSize; crossSize++)
    {
        if (x + crossSize < N && map[x + crossSize][y] == '*' &&
            x - crossSize >= 0 && map[x - crossSize][y] == '*' &&
            y + crossSize < M && map[x][y + crossSize] == '*' &&
            y - crossSize >= 0 && map[x][y - crossSize] == '*')
        {
            answer.push_back({{x + 1, y + 1}, crossSize});
            visited[x][y] = true;
            visited[x + crossSize][y] = true;
            visited[x - crossSize][y] = true;
            visited[x][y + crossSize] = true;
            visited[x][y - crossSize] = true;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    cin >> N >> M;
    maxSize = ((min(N, M) + 1) + 1) / 2 - 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == '*')
            {
                findCross(i, j);
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == '*' && !visited[i][j])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }

    if (flag)
    {
        cout << answer.size() << "\n";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i].first.first << " " << answer[i].first.second << " " << answer[i].second << "\n";
        }
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}
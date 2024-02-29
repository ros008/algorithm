#include <iostream>
#include <vector>

using namespace std;

// 플로이드 와샬

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 0;
    const int MAX = 20000001;

    vector<vector<int>> dist(201, vector<int>(201, MAX));
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < fares.size(); i++)
    {
        int from = fares[i][0], to = fares[i][1], cost = fares[i][2];
        dist[from][to] = cost;
        dist[to][from] = cost;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    // s -> a s -> b 인 경우
    int case1 = dist[s][a] + dist[s][b];

    // s -> t -> a s -> t -> b 인 경우
    int case2 = MAX;
    for (int i = 1; i <= n; i++)
    {
        if (case2 > dist[s][i] + dist[i][a] + dist[i][b])
        {
            case2 = dist[s][i] + dist[i][a] + dist[i][b];
        }
    }

    if (case1 < case2)
        answer = case1;
    else
        answer = case2;

    return answer;
}

int main()
{
    // int n = 6, s = 4, a = 6, b = 2;
    // vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};

    int n = 7, s = 3, a = 4, b = 1;
    vector<vector<int>> fares = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};

    cout << solution(n, s, a, b, fares);

    return 0;
}
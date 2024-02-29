#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> square(rows + 1, vector<int>(columns + 1, 0));
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            square[i][j] = columns * (i - 1) + j;

    for (int k = 0; k < queries.size(); k++)
    {
        int sx = queries[k][0], sy = queries[k][1], ex = queries[k][2], ey = queries[k][3];
        int minV = square[sx][sy];
        int start = square[sx][sy];

        for (int i = sx; i < ex; i++)
        {
            square[i][sy] = square[i + 1][sy];
            minV = min(minV, square[i][sy]);
        }

        for (int i = sy; i < ey; i++)
        {
            square[ex][i] = square[ex][i + 1];
            minV = min(minV, square[ex][i]);
        }

        for (int i = ex; i > sx; i--)
        {
            square[i][ey] = square[i - 1][ey];
            minV = min(minV, square[i][ey]);
        }

        for (int i = ey; i > sy + 1; i--)
        {
            square[sx][i] = square[sx][i - 1];
            minV = min(minV, square[sx][i]);
        }

        square[sx][sy + 1] = start;
        minV = min(minV, square[sx][sy + 1]);

        answer.push_back(minV);
    }

    return answer;
}

int main()
{
    int rows = 6;
    int columns = 6;
    vector<vector<int>> queries = {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}};

    vector<int> ret = solution(rows, columns, queries);

    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }

    return 0;
}
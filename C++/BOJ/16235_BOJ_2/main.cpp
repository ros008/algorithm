#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, M, K, ans = 0;
int addedNutrient[MAX + 1][MAX + 1];
int curNutrient[MAX + 1][MAX + 1];

vector<int> treeAges[MAX + 1][MAX + 1];

void SpringAndSummer()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (treeAges[i][j].size() == 0)
                continue;
            vector<int> newAges;
            int deadNutrient = 0;
            sort(treeAges[i][j].begin(), treeAges[i][j].end());
            for (int k = 0; k < treeAges[i][j].size(); k++)
            {
                int age = treeAges[i][j][k];
                if (curNutrient[i][j] >= age)
                {
                    newAges.push_back(age + 1);
                    curNutrient[i][j] -= age;
                }
                else
                {
                    deadNutrient += (age / 2);
                }
            }
            treeAges[i][j].clear();
            for (int k = 0; k < newAges.size(); k++)
            {
                treeAges[i][j].push_back(newAges[k]);
            }
            curNutrient[i][j] += deadNutrient;
        }
    }
}

void Fall()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (treeAges[i][j].size() == 0)
                continue;
            for (int s = 0; s < treeAges[i][j].size(); s++)
            {
                int age = treeAges[i][j][s];
                if (age % 5 == 0)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                        {
                            treeAges[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void Winter()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            curNutrient[i][j] += addedNutrient[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            curNutrient[i][j] = 5;
            cin >> addedNutrient[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        treeAges[x - 1][y - 1].push_back(age);
    }

    for (int i = 0; i < K; i++)
    {
        SpringAndSummer();
        Fall();
        Winter();
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans += treeAges[i][j].size();
        }
    }

    cout << ans << "\n";

    return 0;
}
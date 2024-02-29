#include <iostream>
#include <vector>

#define MAX 4000

using namespace std;

int N, M, answer = -1;
bool isFriend[MAX + 1][MAX + 1];
int cntFriend[MAX + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        isFriend[a][b] = true;
        isFriend[b][a] = true;
        cntFriend[a]++;
        cntFriend[b]++;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (isFriend[i][j])
            {
                for (int k = j + 1; k <= N; k++)
                {
                    if (isFriend[i][k] && isFriend[j][k])
                    {
                        int sum = cntFriend[i] + cntFriend[j] + cntFriend[k] - 6;
                        if (answer == -1 || answer > sum)
                            answer = sum;
                    }
                }
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
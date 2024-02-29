#include <iostream>
#include <stack>

using namespace std;

int N, K;
int board[12 + 1][12 + 1];
stack<int> malStack[12 + 1][12 + 1];
int turn = 0;
struct info
{
    int r, c, dir;
} mal[10 + 1];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= K; i++)
    {
        cin >> mal[i].r >> mal[i].c >> mal[i].dir;
        malStack[mal[i].r][mal[i].c].push(i);
    }

    while (true)
    {
        ++turn;
        if (turn > 1000)
        {
            turn = -1;
            break;
        }
    }

    cout << turn << "\n";

    return 0;
}
#include <iostream>

using namespace std;

int romeArr[4] = {1, 5, 10, 50};
int len, answer = 0;
bool visited[1000 + 1];

void findNum(int cnt, int d, int cur)
{
    if (cnt == len)
    {
        if (!visited[cur])
        {
            visited[cur] = true;
            answer++;
        }
        return;
    }

    for (int i = d; i < 4; i++)
    {
        findNum(cnt + 1, i, cur + romeArr[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> len;

    findNum(0, 0, 0);
    cout << answer << "\n";

    return 0;
}
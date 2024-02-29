#include <iostream>
#include <vector>

using namespace std;

int N, target, targetX, targetY;
int map[1000 + 1][1000 + 1];

int main()
{
    cin >> N >> target;
    int size = N - 1;
    int x = 0, y = 0, idx = N * N;
    while (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (idx == target)
            {
                targetX = x;
                targetY = y;
            }
            map[x++][y] = idx--;
        }
        for (int i = 0; i < size; i++)
        {
            if (idx == target)
            {
                targetX = x;
                targetY = y;
            }
            map[x][y++] = idx--;
        }
        for (int i = 0; i < size; i++)
        {
            if (idx == target)
            {
                targetX = x;
                targetY = y;
            }
            map[x--][y] = idx--;
        }
        for (int i = 0; i < size; i++)
        {
            if (idx == target)
            {
                targetX = x;
                targetY = y;
            }
            map[x][y--] = idx--;
        }
        y++;
        x++;
        if (size == 2)
        {
            if (idx == target)
            {
                targetX = x;
                targetY = y;
            }
            map[x][y] = 1;
            break;
        }
        else
        {
            size -= 2;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << targetX + 1 << " " << targetY + 1 << "\n";

    return 0;
}
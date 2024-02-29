#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, x, y, nx, ny, nnx, nny;
string instruction;
vector<vector<char>> map(15 + 1, vector<char>(15 + 1));

bool isGameComplete()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'b' || map[i][j] == '+')
            {
                return false;
            }
        }
    }
    return true;
}

void move()
{
    if (map[nx][ny] == 'b' || map[nx][ny] == 'B')
    {
        if (map[nnx][nny] == '+')
        {
            map[nnx][nny] = 'B';
        }
        else if (map[nnx][nny] == '.')
        {
            map[nnx][nny] = 'b';
        }
        else
        {
            return;
        }

        if (map[nx][ny] == 'b')
        {
            map[nx][ny] = 'w';
        }
        else if (map[nx][ny] == 'B')
        {
            map[nx][ny] = 'W';
        }

        if (map[x][y] == 'W')
        {
            map[x][y] = '+';
        }
        else if (map[x][y] == 'w')
        {
            map[x][y] = '.';
        }
        x = nx;
        y = ny;
    }
    else if (map[nx][ny] == '.' || map[nx][ny] == '+')
    {
        if (map[nx][ny] == '.')
        {
            map[nx][ny] = 'w';
        }
        else if (map[nx][ny] == '+')
        {
            map[nx][ny] = 'W';
        }

        if (map[x][y] == 'W')
        {
            map[x][y] = '+';
        }
        else if (map[x][y] == 'w')
        {
            map[x][y] = '.';
        }
        x = nx;
        y = ny;
    }
}

int main()
{
    int tc = 1;
    while (1)
    {
        bool endFlag = false;
        cin >> R >> C;
        if (R == 0 && C == 0)
            break;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'w')
                {
                    x = i;
                    y = j;
                }
            }
        }
        cin >> instruction;

        for (int i = 0; i < instruction.length(); i++)
        {
            if (isGameComplete())
            {
                endFlag = true;
                break;
            }
            if (instruction[i] == 'U')
            {
                nx = x - 1;
                ny = y;
                nnx = x - 2;
                nny = y;
            }
            else if (instruction[i] == 'D')
            {
                nx = x + 1;
                ny = y;
                nnx = x + 2;
                nny = y;
            }
            else if (instruction[i] == 'L')
            {
                nx = x;
                ny = y - 1;
                nnx = x;
                nny = y - 2;
            }
            else if (instruction[i] == 'R')
            {
                nx = x;
                ny = y + 1;
                nnx = x;
                nny = y + 2;
            }
            move();
        }

        if (endFlag || isGameComplete())
        {
            cout << "Game " << tc++ << ": complete"
                 << "\n";
        }
        else
        {
            cout << "Game " << tc++ << ": incomplete"
                 << "\n";
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << map[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
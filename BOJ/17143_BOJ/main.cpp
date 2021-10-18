#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark
{
    int r;
    int c;
    int speed;
    int dir;
    int size;
};

int R, C, M;
vector<Shark> sharkArr;

int main()
{
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharkArr.push_back({r, c, s, d, z});
    }

    return 0;
}
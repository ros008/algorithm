#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark
{
    int r, c, s, d, z; // r: 행, c: 열, s: 속도, d: 방향, z: 크기
};

int dir[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

int R, C, M, ans = 0;
vector<Shark> sharkArr[100+2][100+2];

void Print() {
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            cout<< (sharkArr[i][j].size() > 0 ? sharkArr[i][j][0].z : 0) << " ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int changeDir(int dir) {
    if(dir == 1) return 2;
    if(dir == 2) return 1;
    if(dir == 3) return 4;
    if(dir == 4) return 3;
}

void moveShark() {
    vector<Shark> newSharkArr[100+2][100+2];
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(sharkArr[i][j].size() == 0) continue;
            Shark curShark = sharkArr[i][j][0];
            sharkArr[i][j].pop_back();

            cout<<curShark.r<<" "<<curShark.c<<"\n";

            int& curR = curShark.r;
            int& curC = curShark.c;
            int curS = curShark.s;
            int& curD = curShark.d;
            
            while(curS--) {
                int nr = curR + dir[curD][0];
                int nc = curC + dir[curD][1];
                if (nr <= 0 || nr > R || nc <= 0 || nc > C) {
                    curD = changeDir(curD);
                } 
                curR += dir[curD][0];
                curC += dir[curD][1];
            }
            // cout<<curR<<" "<<curC<<" "<<curD<<" " <<curShark.z<<"\n";

            if (newSharkArr[curR][curC].size() > 0) {
                if (newSharkArr[curR][curC][0].z < curShark.z) {
                    newSharkArr[curR][curC].pop_back();
                    newSharkArr[curR][curC].push_back(curShark);
                }
            } else {
                newSharkArr[curR][curC].push_back(curShark);
            }   
        }

        for (int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++) {
                sharkArr[i][j] = newSharkArr[i][j];
            }
        }
    }
}

void fishing(int pos) {
    for(int i=1; i<=R; i++) {
        if(sharkArr[i][pos].size() > 0) {
            ans += sharkArr[i][pos][0].z;
            sharkArr[i][pos].pop_back();
            break;
        }
    }
}

int main()
{
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        if (d == 1 || d == 2)  s %= ((R - 1) * 2); 
        if (d == 3 || d == 4)  s %= ((C - 1) * 2);
        sharkArr[r][c].push_back({r, c, s, d, z});
    }

    for(int pos = 1; pos <= C; pos++) {
        fishing(pos);
        Print();
        moveShark();
        // Print();
    }

    cout<<ans<<"\n";

    return 0;
}
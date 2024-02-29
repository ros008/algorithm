#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

int N,M, ans = 0;
int map[101][101];
int checkedMap[101][101];
bool visited[101][101];

void eraseCheese() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(checkedMap[i][j] >= 2) {
                map[i][j] = 0;
            }
        }
    }
}

bool bfs() {
    memset(visited, false, sizeof(visited));
    memset(checkedMap, 0, sizeof(checkedMap));
    queue<pair<int,int>> q;
    int cnt = 0;

    q.push({0,0});
    visited[0][0];

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >=M) continue;
            if(map[nx][ny] == 1) {
                checkedMap[nx][ny]++;
                cnt++;
            } else if (map[nx][ny] == 0 && !visited[nx][ny]) {
                q.push({nx, ny});
            }
            visited[nx][ny] = true;
        }
    }
    
    eraseCheese();

    if(cnt == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>map[i][j];
        }
    }

    while(1) {
        if(bfs()) {
            break;
        }
        ans++;
    }

    cout<<ans<<"\n";

    return 0;
}
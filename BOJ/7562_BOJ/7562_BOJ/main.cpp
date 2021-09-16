//
//  main.cpp
//  7562_BOJ
//
//  Created by Sujin Kim on 2021/01/06.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool visited[301][301];
int map[301][301];

int l;
pair<int, int> s,e;

void bfs () {
    queue<pair<int, int>> q;
    visited[s.first][s.second] = true;
    q.push(make_pair(s.first, s.second));
    
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        if(cur.first == e.first && cur.second == e.second) {
            cout << map[cur.first][cur.second] << "\n";
            return;
        }
        
        for(int i=0; i<8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny]){
                visited[nx][ny] = true;
                map[nx][ny] = map[cur.first][cur.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        cin>>l;
        cin>>s.first>>s.second;
        cin>>e.first>>e.second;
        
        bfs();
    }
    return 0;
}

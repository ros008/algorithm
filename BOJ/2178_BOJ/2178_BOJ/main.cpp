//
//  main.cpp
//  2178_BOJ
//
//  Created by Sujin Kim on 2020/08/20.
//  Copyright © 2020 Sujin Kim. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[101][101];
int visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(0, 0),1));
    visited[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        
        q.pop();
        
        if(x == N-1 && y == M-1)
            return d;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M) {
                if(visited[nx][ny] == 0 && map[nx][ny] == '1') {
                    q.push(make_pair(make_pair(nx, ny), d+1));
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map[i][j] = '0';
            visited[i][j] = 0;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    cout << bfs();
    
    return 0;
}

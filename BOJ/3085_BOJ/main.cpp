#include <iostream>

using namespace std;

int N, ans = 0;
char map[51][51];

void findMaxCandy() {
    // 행
    for(int i=0; i<N; i++) {
        int cnt = 1;
        char c = map[i][0];
        for(int j=1; j<N; j++) {
            if(c == map[i][j]) {
                cnt++;
            }
            else {
                cnt = 1;
                c = map[i][j];
            }
            if(ans < cnt) {
                ans = cnt;
            }
        }
    }
    // 열
    for(int i=0; i<N; i++) {
        int cnt =1;
        char c= map[0][i];
        for(int j=1; j<N; j++){
            if(c == map[j][i]) {
                cnt++;
            } else {
                cnt = 1;
                c = map[j][i];
            }
            if(ans < cnt) {
                ans = cnt;
            }
        }
    }
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N-1; j++) {
            swap(map[i][j], map[i][j+1]);
            findMaxCandy();
            swap(map[i][j], map[i][j+1]);
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N-1; j++) {
            swap(map[j][i], map[j+1][i]);
            findMaxCandy();
            swap(map[j][i], map[j+1][i]);
        }
    }
    
    cout<<ans<<"\n";

    return 0;
}
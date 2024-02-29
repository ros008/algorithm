#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Rotate {
    int r,c,s;
};

int N, M, K, ans=INF;
int map[50+5][50+5];
int mapCopied[50+5][50+5];
vector<int> seq;
Rotate rotationInfo[6+5];

void printMap() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cout<<mapCopied[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void rotateMap(int r, int c, int step) {
    int first = mapCopied[r-step][c-step];
    for(int i=r-step+1; i<=r+step; i++) {
        mapCopied[i-1][c-step] = mapCopied[i][c-step];
    }
    for(int i=c-step+1; i<=c+step; i++) {
        mapCopied[r+step][i-1] = mapCopied[r+step][i];
    }
    for(int i=r+step-1; i>=r-step; i--) {
        mapCopied[i+1][c+step] = mapCopied[i][c+step];
    }
    for(int i=c+step-1; i>=c-step+1; i--) {
        mapCopied[r-step][i+1] = mapCopied[r-step][i];
    }
    mapCopied[r-step][c-step+1] = first;
}

void findRowSum() {
    for(int i=1; i<=N; i++) {
        int sum = 0;
        for(int j=1; j<=M; j++) {
            sum+=mapCopied[i][j];
        }
        if(ans>sum) ans=sum;
    }
}

int main() {
    cin>>N>>M>>K;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin>>map[i][j];
        }
    }
    for(int i=1; i<=K; i++) {
        cin>>rotationInfo[i].r>>rotationInfo[i].c>>rotationInfo[i].s;
        seq.push_back(i);
    }

    do {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                mapCopied[i][j] = map[i][j];
            }
        }
        for(int i=0; i<seq.size(); i++) {
            for(int j=1; j<=rotationInfo[seq[i]].s; j++) {
                rotateMap(rotationInfo[seq[i]].r, rotationInfo[seq[i]].c, j);
            }
            // printMap();
        }
        findRowSum();

    } while(next_permutation(seq.begin(), seq.end()));

    cout<<ans<<"\n";

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

#define INF 987654321

using namespace std;

int N, M, D, ans = 0;

int getDist (int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int castleDefence (vector<int> archers, list<pair<int,int>> enemies) {
    int ret = 0;

    while(!enemies.empty()) {
        set<pair<int,int>> targetEnemy;
    
        for(vector<int>::iterator archer = archers.begin(); archer != archers.end(); archer++) {
            int minX = INF, minY = INF, minDist = INF;
            for(list<pair<int,int>>::iterator enemy = enemies.begin(); enemy != enemies.end(); enemy++) {
                int dist = abs(N - enemy->first) + abs(*archer - enemy->second);
                if(dist <= D && (dist < minDist || (dist == minDist && enemy->second < minY))) {
                    minX = enemy->first;
                    minY = enemy->second;
                    minDist = dist;
                }
            }
            if(minDist != INF) targetEnemy.emplace(minX, minY);
        }

        for(set<pair<int,int>>::iterator target = targetEnemy.begin(); target!=targetEnemy.end(); target++) {
            for(list<pair<int,int>>::iterator enemy = enemies.begin(); enemy != enemies.end(); ) {
                if(target->first == enemy->first && target->second == enemy->second) {
                    enemies.erase(enemy);
                    ret++;
                    break;
                }
                enemy++;
            }
        }

        // 적 아래로 한 칸씩 이동
        for(list<pair<int,int>>::iterator enemy = enemies.begin(); enemy != enemies.end(); ) {
            enemy->first++;
            if(enemy->first == N) {
                enemies.erase(enemy);
            } else {
                enemy++;
            }
        }
    }

    return ret;
}

int main() {
    vector<int> comb;
    list<pair<int,int>> enemies;

    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int isEnemy; cin >> isEnemy;
            if(isEnemy) {
                enemies.emplace_back(i, j);
            }
        }
    }

    for (int i = 0; i < 3; i++) 
        comb.push_back(1);
    for(int i = 0; i < M - 3; i++) 
        comb.push_back(0);
    sort(comb.begin(), comb.end());

    do {
        vector<int> archers;
        for (int i = 0; i < comb.size(); i++) {
            if (comb[i] == 1) {
                archers.push_back(i);
            }
        }
        int ret = castleDefence(archers, enemies);
        ans = max(ans, ret);
    } while(next_permutation(comb.begin(), comb.end()));
    
    cout<<ans<<"\n";

    return 0;
}
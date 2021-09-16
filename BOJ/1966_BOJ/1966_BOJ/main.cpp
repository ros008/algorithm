//
//  main.cpp
//  1966_BOJ
//
//  Created by Sujin Kim on 2020/12/29.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        queue<pair<int,int>> docuList;
        priority_queue<int> pq;
        
        int printCnt = 0;
        
        for(int i=0; i<n; i++) {
            int v;
            cin >> v;
            docuList.push(make_pair(i, v));
            pq.push(v);
        }
        
        while(!docuList.empty()) {
            pair<int, int> cur = docuList.front();
            
            if(pq.top() > cur.second) {
                docuList.push(docuList.front());
                docuList.pop();
            }
            else {
                docuList.pop();
                pq.pop();
                printCnt++;
                if(cur.first == m) {
                    cout << printCnt << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}

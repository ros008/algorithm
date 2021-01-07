//
//  main.cpp
//  1946_BOJ
//
//  Created by Sujin Kim on 2020/08/18.
//  Copyright © 2020 Sujin Kim. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int main(int argc, const char * argv[]) {
    int tc, n;
    vector<pair<int,int>> score;
    cin >> tc;
    for(int t=1; t<=tc; t++) {
        score.clear();
        cin >> n;
        for(int i=0; i<n; i++){
            int a,b;
            cin>>a>>b;
            score.push_back(make_pair(a, b));
        }
        sort(score.begin(), score.end(), compare);
        
    }
    
    
    return 0;
}

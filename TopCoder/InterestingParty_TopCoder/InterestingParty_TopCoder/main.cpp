//
//  main.cpp
//  InterestingParty_TopCoder
//
//  Created by Sujin Kim on 2021/01/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using  namespace std;

int interestingParty(vector<string> first, vector<string> second) {
    int ans = 0;
    map<string, int> m;
    for(int i=0; i<first.size(); i++) {
        m[first[i]] = 0;
        m[second[i]] = 0;
    }
    
    for(int i=0; i<first.size(); i++) {
        m[first[i]]++;
        m[second[i]]++;
    }
    
    for(auto it=m.begin(); it!=m.end(); it++) {
        ans = max(ans, it->second);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<string> first = {"fishing","gardening", "swimming", "fishing"};
    vector<string> second = {"hunting","fishing", "fishing", "biting"};
    cout<<interestingParty(first, second);
    return 0;
}

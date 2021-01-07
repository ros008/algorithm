//
//  main.cpp
//  test
//
//  Created by Sujin Kim on 2020/08/01.
//  Copyright © 2020 Sujin Kim. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> interestingDigits2(int base) {
    vector<int> ans;
    for(int i=2; i<base; i++) {
        if(((base-1) %i) == 0) ans.push_back(i);
    }
    return ans;
}

vector<int> interestingDigits(int base) {
    vector<int> ans;
    
    for(int i=2; i<base; i++) {
        bool flag = true;
        for(int k1=0; k1<base; k1++){
            for(int k2=0; k2<base; k2++) {
                for(int k3=0; k3<base; k3++){
                    if((k1 + k2*base + k3*base*base) % i == 0 && (k1 + k2 + k3) % i != 0) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        if(flag) ans.push_back(i);
    }
    
    return ans;
}

int main() {
    vector<int> ans = interestingDigits(26);
    
    for(auto a : ans) cout<< a <<"\n";
    
    return 0;
}

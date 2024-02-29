//
//  main.cpp
//  1120_BOJ
//
//  Created by Sujin Kim on 2020/08/17.
//  Copyright © 2020 Sujin Kim. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string a, b;
    cin >> a >> b;
    int num = b.length() - a.length() + 1;
    int minDiff = 100;
    
    for(int i=0; i<num; i++){
        int diff = 0;
        for(int j=0; j<a.length(); j++){
            if(a[j] != b[i + j]){
                diff++;
            }
        }
        minDiff = min(minDiff, diff);
    }
    cout<<minDiff;
    
    return 0;
}

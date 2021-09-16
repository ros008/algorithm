//
//  main.cpp
//  KiwiJuiceEasy_TopCoder
//
//  Created by Sujin Kim on 2020/11/29.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId){
    
    for(int i=0; i<fromId.size(); i++) {
        int f = fromId[i];
        int t = toId[i];
        
        int diff = min(bottles[f], capacities[t] - bottles[t]);
        
        bottles[f] -= diff;
        bottles[t] += diff;
    }
    
    return bottles;
}

int main(int argc, const char * argv[]) {
    vector<int> capacities = {14,35,86,58,25,62};
    vector<int> bottles = {6,34,27,38,9,60};
    vector<int> fromId = {1,2,4,5,3,3,1,0};
    vector<int> toId = {0,1,2,4,2,5,3,1};
    
    vector<int> rst = thePouring(capacities, bottles, fromId, toId);
    
    for(int value:rst){
        cout<<value<<endl;
    }
    
    return 0;
}

//
//  main.cpp
//  15666_BOJ
//
//  Created by Sujin Kim on 2021/02/02.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> arr;
vector<int> v;

void Print() {
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return;
}

void dfs(int idx, int cnt) {
    if(cnt == m) {
        Print();
        return;
    }
    for(int i=idx; i<arr.size(); i++) {
        v.push_back(arr[i]);
        dfs(i, cnt+1);
        v.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        if(find(arr.begin(), arr.end(), num) == arr.end()) {
            arr.push_back(num);
        }
    }
    sort(arr.begin(), arr.end());
    
    dfs(0, 0);
    
    return 0;
}

//
//  main.cpp
//  15655_BOJ
//
//  Created by Sujin Kim on 2021/02/02.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool visited[10];
vector<int> arr;
vector<int> v;

void Print() {
    for(int i=0; i<v.size(); i++) {
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
    for(int i=idx; i<n; i++){
        if(!visited[i]) {
            visited[i] = true;
            v.push_back(arr[i]);
            dfs(i+1, cnt+1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    dfs(0, 0);
    
    return 0;
}

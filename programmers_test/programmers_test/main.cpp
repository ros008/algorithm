#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    set<string>::iterator iter;
    s.insert(words[0]);
    
    for(int i=1; i<words.size(); i++) {
        cout<< words[i]<< "\n";
        iter = s.find(words[i]);
        if(words[i-1].back() != words[i].front() || iter != s.end()) {
            cout<<i<<"\n";
            answer.push_back(i/n + 1);
            answer.push_back(i%n +1);
            break;
        }
        s.insert(words[i]);
    }
    if(answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 3;
    vector<string> s = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    
    vector<int> ans = solution(n, s);
    cout<< ans[0] << " " << ans[1];
    return 0;
}



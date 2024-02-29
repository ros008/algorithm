#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int answer = s.length();

    int len = s.length();
    for (int i = 1; i <= len / 2; i++) {
        int cnt = 1;
        string cmp = s.substr(0, i);
        string newStr = "";

        for(int j = i; j < len; j += i) {
            string cur = s.substr(j, i);
            if(cmp.compare(cur) == 0) {
                cnt++;
            } else {
                if(cnt == 1) {
                    newStr += cmp;
                } else {
                    newStr += (to_string(cnt) + cmp);
                    cnt = 1;
                }
                cmp = cur;
            }
            if(j + i >= len) {
                if (cnt == 1) {
                    newStr += s.substr(j);
                } else {
                    newStr += (to_string(cnt) + cmp);
                }
                break;
            }
        }
        cout << newStr << "\n";
        answer = (answer > newStr.length()) ? newStr.length() : answer;
    }
    return answer;
}

int main() {
    string s = "aabbaccc";
    
    cout << solution(s);

    return 0;
}
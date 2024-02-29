//
//  main.cpp
//  ThePalindrome_TopCoder
//
//  Created by Sujin Kim on 2021/01/19.
//

#include <iostream>
#include <string>

using namespace std;

int minLenPalindrome(string str) {
    for(int i=str.size(); ; i++) {
        bool flag = true;
        for(int j=0; j<str.size(); j++) {
            if(i-j-1 < str.size() && str[j]  != str[i-j-1]){
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
}

int main() {
    string str = "abdfhdyrbdbsdfghjkllkjhgfds";
    cout << minLenPalindrome(str);
    return 0;
}

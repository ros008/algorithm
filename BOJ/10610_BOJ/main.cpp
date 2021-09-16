#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(char a, char b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string str;
	cin >> str;

	int cnt = 0;

	for (int i = 0; i < str.length(); i++) {
		cnt += str[i] - '0';
	}

	sort(str.begin(), str.end(), comp);

	if(cnt%3 == 0 && str[str.length()-1] - '0' == 0){
		cout << str;
	}
	else {
		cout << -1;
	}

	
	return 0;
}
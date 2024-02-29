#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string str;
int cnt = 0;

int main() {

	int tc;
	cin >> tc;

	for(int t = 1; t <= tc; t++) {

		cin >> str;
		cnt = 0;

		int first_index = -1;

		for (int i = 0; i < str.length(); i++) {
			if (first_index == -1 && str[i] == 1) {
				first_index = i;
				cnt++;
			}
			else if (i > 0 && str[i - 1] != str[i]) {
				cnt++;
			}

		}

		if (str[0] == '1') cnt+=1;


		cout << "#" << t << " " << cnt << "\n";
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string str;

int main() {

	cin >> str;

	bool minus_flag = false;
	int result = 0;

	string tmp = "";

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0') {
			if (minus_flag) {
				result -= stoi(tmp);
			}
			else {
				result += stoi(tmp);
			}

			tmp = "";

			if (str[i] == '-') {
				minus_flag = true;
			}
		}
		else {
			tmp += str[i];
		}
		
	}

	cout << result;

	return 0;
}
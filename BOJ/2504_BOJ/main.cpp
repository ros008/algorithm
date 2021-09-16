#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string str;
	stack<int> s; // ( = -1,  [ = -2
	int sum, result = 0;

	cin >> str;

	if (str.size() == 1) {
		cout << result;
		return 0;
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {
				s.push(2);
				i++;
			}
			else {
				s.push(-1);
			}
		}
		else if (str[i] == '[') {
			if (str[i + 1] == ']') {
				s.push(3);
				i++;
			}
			else {
				s.push(-2);
			}
		}
		else if(str[i] == ')') {
			sum = 0;
			while (!s.empty() && s.top() != -1) {
				sum += s.top();
				s.pop();
			}

			if (s.empty()) {
				result = 0;
				break;
			}

			s.pop();
			s.push(sum * 2);
		}
		else if (str[i] == ']') {
			sum = 0;
			while (!s.empty() && s.top() != -2) {
				sum += s.top();
				s.pop();
			}

			if (s.empty()) {
				result = 0;
				break;
			}

			s.pop();
			s.push(sum * 3);
		}
	}

	while (!s.empty()) {
		if (s.top() < 0) {
			result = 0;
			break;
		}
		result += s.top();
		s.pop();
	}

	cout << result;

	return 0;
}

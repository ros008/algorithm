#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		string input;
		cin >> input;

		list<char> result;
		list<char>::iterator cursor = result.begin();

		for (int i = 0; i < input.size(); i++) {
			switch (input[i]) {
			case '-':
				if (cursor != result.begin()) result.erase((--cursor)++);
				break;
			case '<':
				if (cursor != result.begin()) cursor--;
				break;
			case '>':
				if (cursor != result.end()) cursor++;
				break;
			default:
				result.insert(cursor, input[i]);
				break;
			}
		}

		for (auto x : result) 
			cout << x;
		cout << "\n";
	}

	return 0;
}
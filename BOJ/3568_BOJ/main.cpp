#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void sol(string s) {
	for (int i = s.size() - 2; i >= 0; i--) {
		if (s[i] == ']') {
			cout << "[]";
			i--;
		}
		else if (s[i] == '&' || s[i] == '*') {
			cout << s[i];
		}
		else {
			cout << " ";
			for (int j = 0; j <= i; j++)
				cout << s[j];
			cout << ";\n";
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string ss;
	getline(cin, ss);
	stringstream input(ss);
	string datatype, variable;

	input >> datatype;

	while (input >> variable) {
		cout << datatype;
		sol(variable);
	}

	return 0;
}
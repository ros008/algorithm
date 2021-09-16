#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int tc; cin >> tc;

	for (int t = 0; t < tc; t++) {

		unordered_map<string, int> data;

		int n; cin >> n;

		for (int i = 0; i < n; i++) {
			string name;
			string kind;

			cin >> name >> kind;

			if (data.find(kind) == data.end()) {
				data.insert({ kind, 1 });
			}
			else {
				data[kind]++;
			}
		}

		int result = 1;
		for (auto kind : data) {
			result *= (kind.second + 1);
		}
		result -= 1;
		cout << result << '\n';


	}

	return 0;
}
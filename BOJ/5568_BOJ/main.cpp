#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n, k;
unordered_set<string> newInt;
string input[10];
bool chk[10];

void makeInt(int cnt, string cur) {
	if (cnt == k) {
		newInt.insert(cur);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			chk[i] = true;
			makeInt(cnt + 1, cur + input[i]);
			chk[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> input[i];

	makeInt(0, "");
	cout << newInt.size() << "\n";

	return 0;
}
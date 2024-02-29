#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
bool isFriend[10][10];

int countPairs(bool hasPair[]) {
	int ret = 0;
	int candidate = -1;
	
	for (int i = 0; i < n; i++) {
		if (!hasPair[i]) {
			candidate = i;
			break;
		}
	}

	if (candidate == -1) return 1;
	
	for (int i = candidate + 1; i < n; i++) {
		if (!hasPair[i] && isFriend[candidate][i]) {
			hasPair[candidate] = hasPair[i] = true;
			ret += countPairs(hasPair);
			hasPair[candidate] = hasPair[i] = false;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m;
		memset(isFriend, false, sizeof(isFriend));

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			isFriend[a][b] = isFriend[b][a] = true;
		}

		bool tmp[10];
		memset(tmp, false, sizeof(tmp));
		cout << countPairs(tmp) << "\n";
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 10000;

bool visited[MAX];

string bfs(int a, int b) {
	queue<pair<int, string>> q; // 숫자, 연산 횟수
	q.push({ a, "" });
	visited[a] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		string str = q.front().second;
		q.pop();

		if (cur == b) return str;

		int nx;
		nx = cur * 2;
		if (nx > 9999) nx = nx % 10000;
		if (!visited[nx]) {
			q.push({ nx, str + "D" });
			visited[nx] = true;
		}

		nx = cur - 1;
		if (nx < 0) nx = 9999;
		if (!visited[nx]) {
			q.push({ nx, str + "S" });
			visited[nx] = true;
		}

		nx = (cur % 1000) * 10 + (cur / 1000);
		if (!visited[nx]) {
			q.push({ nx, str + "L" });
			visited[nx] = true;
		}

		nx = (cur % 10) * 1000 + (cur / 10);
		if (!visited[nx]) {
			q.push({ nx, str + "R" });
			visited[nx] = true;
		}
	}
	return "";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		memset(visited, false, sizeof(visited));

		int a, b;
		cin >> a >> b;
		string ans = bfs(a, b);
		cout << ans << "\n";
	}

	return 0;
}
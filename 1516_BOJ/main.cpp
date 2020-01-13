#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 500;

int time[MAX + 1];
int indegree[MAX + 1];
vector<int> v[MAX + 1];
int ans[MAX + 1];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, t, num;
	cin >> n;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		cin >> t;
		time[i] = t;

		while (1) {
			cin >> num;
			if (num == -1) break;
			v[num].push_back(i);
			indegree[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			ans[i] = time[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			ans[v[cur][i]] = max(ans[v[cur][i]], time[v[cur][i]] + ans[cur]);
			indegree[v[cur][i]]--;
			if (indegree[v[cur][i]] == 0) {
				q.push(v[cur][i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
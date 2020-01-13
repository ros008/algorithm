#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[32001];
vector<int> v[32001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b;
	cin >> n >> m;

	while (m--) {
		cin >> a >> b;
		indegree[b]++;
		v[a].push_back(b);
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) 
		if (indegree[i] == 0) q.push(i);

	while (!q.empty()) {
		int a = q.front();
		q.pop();
		cout << a << " ";

		for (int i = 0; i < v[a].size(); i++) {
			indegree[v[a][i]]--;
			if (indegree[v[a][i]] == 0) q.push(v[a][i]);
		}
	}

	return 0;
}
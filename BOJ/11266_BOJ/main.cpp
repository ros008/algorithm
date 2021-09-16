#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000

using namespace std;

vector<int> vec[MAX + 1];
int visited[MAX + 1];
bool cut[MAX + 1];

int d = 0;

int dfs(int cur, bool isroot) {
	visited[cur] = ++d; // Å½»ö ¼ø¼­
	int ret = visited[cur];

	int child = 0;
	for (int i = 0; i < vec[cur].size(); i++) {
		if (visited[vec[cur][i]]) {
			ret = min(ret, visited[vec[cur][i]]);
			continue;
		}
		child++;
		int prev = dfs(vec[cur][i], false);
		if (!isroot && prev >= visited[cur])
			cut[cur] = true;

		ret = min(ret, prev);
	}

	if (isroot)
		cut[cur] = (child >= 2);

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int v, e;
	int a, b;

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) 
		if (!visited[i])
			dfs(i, true);

	int ans = 0;
	for (int i = 1; i <= v; i++)
		if (cut[i])
			ans++;
	cout << ans << "\n";
	for (int i = 1; i <= v; i++)
		if (cut[i])
			cout << i << " ";

	return 0;
}
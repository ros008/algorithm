#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int candidates[10];
int visited[10];
vector<int> combi;

void helper(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << combi[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			combi.push_back(candidates[i]);
			visited[i] = true;
			helper(cnt + 1);
			combi.pop_back();
			visited[i] = false;
			// 중복 제거
			while (candidates[i] == candidates[i + 1]) {
				i++;
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> candidates[i];
	}
	sort(candidates, candidates+n);

	helper(0);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void helper(vector<vector<int>>& ans, vector<int> candidates, vector<int>& cur, int cnt, int start) {
	if (cnt < 0)
		return;
	if (cnt == 0) {
		ans.push_back(cur);
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		if (i == start || candidates[i] != candidates[i - 1]) {
			cur.push_back(candidates[i]);
			helper(ans, candidates, cur, cnt - 1, i + 1);
			cur.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> ans;
	vector<int> candidates(n);

	for (int i = 0; i < n; i++) {
		cin >> candidates[i];
	}

	sort(candidates.begin(), candidates.end());
	vector<int> tmp;
	helper(ans, candidates, tmp, m, 0);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int map[51][51];
bool visited[13];
int ans = INF;

int getDist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx, int selected) { // idx 현재인덱스, selected선택된치킨잡개수
	if (selected == m) {
		int distSum = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = INF;
			for (int j = 0; j < chicken.size(); j++) {
				if (visited[j]) {
					dist = min(dist, getDist(house[i], chicken[j]));
				}
			}
			distSum += dist;
		}
		ans = min(ans, distSum);
		return;
	}

	if (idx == chicken.size())
		return;

	visited[idx] = true;
	dfs(idx + 1, selected + 1);
	visited[idx] = false;
	dfs(idx + 1, selected);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back({ i, j });
			else if (map[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
		
	dfs(0, 0);
	cout << ans << "\n";

	return 0;
}
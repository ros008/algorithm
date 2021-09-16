#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

const int MAX = 1000 + 1;

int N, M;
double ans = 0;
vector<pair<int, int>> alienPos(MAX);
vector<int> parent(MAX);

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> alienPos[i].first >> alienPos[i].second;
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Merge(a, b);
	}

	priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			double x1 = alienPos[i].first;
			double y1 = alienPos[i].second;
			double x2 = alienPos[j].first;
			double y2 = alienPos[j].second;
			double dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
			pq.push({ dist,{i,j} });
		}
	}

	int cnt = M;
	while (!pq.empty() && cnt!= N - 1) {
		double dist = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();
		if (Find(u) != Find(v)) ans += sqrt(dist);
		cnt++;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans << "\n";

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int f, s, g, u, d;
int minBtn = INF;
bool visited[1000001];
int dist[1000001];

void bfs() {
	queue<int> q; // ÇöÀçÃþ, ¿òÁ÷ÀÎ È½¼ö
	q.push(s);
	dist[s] = 0;
	visited[s] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int next = cur + u;
		if (next <= f && !visited[next]) {
			visited[next] = true;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}

		next = cur - d;
		if (next >= 1 && !visited[next]) {
			visited[next] = true;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
	if (visited[g]) 
		cout << dist[g] << "\n";
	else 
		cout << "use the stairs" << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> f >> s >> g >> u >> d;
	bfs();

	return 0;
}
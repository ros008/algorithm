#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

int dist[11][11];
int N;

int tsp(int start, int here, vector<bool>& visited, int curDist, int cnt) {
	if (cnt == N && start == here) 
		return curDist;
	
	int ret = INF;
	for (int next = 0; next < N; next++) {
		if (visited[next] || dist[here][next] == 0) continue;
		visited[next] = true;
		int nextDist = tsp(start, next, visited, curDist + dist[here][next], cnt + 1);
		ret = min(ret, nextDist);
		visited[next] = false;		
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> dist[i][j];

	int result = INF;
	vector<bool> visited(N, false);
	result = min(result, tsp(0, 0, visited, 0, 0));
	
	cout << result << "\n";

	return 0;
}
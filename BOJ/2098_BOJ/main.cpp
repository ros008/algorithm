#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int n;
int w[16][16];
int dp[16][1 << 16];

int tsp(int cur, int visited) {
	int result;
	int ret = dp[cur][visited];

	if (ret != 0) // 이미 방문 했으면
		return ret;

	if (visited == (1 << n) - 1) { // 모두 방문 했다면
		if (w[cur][0] != 0) // 0 마을로 돌아 갈 수 있다면
			return w[cur][0];
		return INF; // 0 마을로 돌아 갈 수 없다면
	}

	ret = INF;
	for (int next = 0; next < n; next++) { // 다음 목적지를 살피면서
		if (visited & 1 << next || w[cur][next] == 0) // 길이 없거나 이미 방문 했다면 패스
			continue;
		result = tsp(next, (visited | 1 << next)) + w[cur][next];
		if (result < ret) 
			ret = result;
	}	
	dp[cur][visited] = ret;
	
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];


	cout << tsp(0, 1) << "\n";

	return 0;
}
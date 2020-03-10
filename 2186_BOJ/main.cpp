#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 100 + 1;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int N, M, K, ans = 0;
string dest;
char map[MAX][MAX];
int dp[MAX][MAX][81]; // (a,b)에 있는 알파벳을 c번 인덱스로 설정했을 때 나올 수 있는 정답의 개수

int dfs(int x, int y, int idx) {
	if (dp[x][y][idx] != -1) return dp[x][y][idx];
	if (idx >= dest.length()) return 1;
	dp[x][y][idx] = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 1; k <= K; k++) {
			int nx = x + dx[i] * k;
			int ny = y + dy[i] * k;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] != dest[idx]) continue;

			dp[x][y][idx] += dfs(nx, ny, idx + 1);
		}
	}
	return dp[x][y][idx];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	cin >> dest;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == dest[0])
				ans += dfs(i, j, 1);


	cout << ans << "\n";

	return 0;
}
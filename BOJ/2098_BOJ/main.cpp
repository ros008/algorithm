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

	if (ret != 0) // �̹� �湮 ������
		return ret;

	if (visited == (1 << n) - 1) { // ��� �湮 �ߴٸ�
		if (w[cur][0] != 0) // 0 ������ ���� �� �� �ִٸ�
			return w[cur][0];
		return INF; // 0 ������ ���� �� �� ���ٸ�
	}

	ret = INF;
	for (int next = 0; next < n; next++) { // ���� �������� ���Ǹ鼭
		if (visited & 1 << next || w[cur][next] == 0) // ���� ���ų� �̹� �湮 �ߴٸ� �н�
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
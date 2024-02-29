#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// mi ������� ����Ʈ��
// ci ���� ��Ȱ��ȭ �� ��� ��� ���
// ci�� �ּҷ� �ϵ� mi >= m

int mi[101], ci[101];
int dp[10001]; // dp[��� ���]=Ȯ�������� �ִ� �޸� ��, cost<=100 n<=100
int n, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> mi[i];
	for (int i = 0; i < n; i++)
		cin >> ci[i];

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		int cost = ci[i];
		for (int j = 10000; j >= cost; j--) {
			if (dp[j - cost] == -1) continue;
			if (dp[j - cost] + mi[i] > dp[j]) dp[j] = dp[j - cost] + mi[i];
		}
		if (dp[cost] < mi[i]) dp[cost] = mi[i]; // dp ���� �ȵ�� ������
	}

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= m) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}
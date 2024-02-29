#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int arr[501][501];
int cnt[501];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int a, b;
	int ans = 0;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = INF;
		
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}
	
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != INF) {
				cnt[i]++; cnt[j]++;
				if (cnt[i] == n - 1) ans++;
				if (cnt[j] == n - 1) ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
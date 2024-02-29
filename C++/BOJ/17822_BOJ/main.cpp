#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int n, m, t;
deque<int> onepan[51];

void turn(int x, int d, int k) {
	for (int i = 0; i < k; i++) {
		if (d == 0) { // 시계
			int tmp = onepan[x].back();
			onepan[x].pop_back();
			onepan[x].push_front(tmp);
		}
		else if (d == 1) { // 반시계
			int tmp = onepan[x].front();
			onepan[x].pop_front();
			onepan[x].push_back(tmp);
		}
	}
}

void deleteNum() {
	bool found = false;

	// 좌우
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == m - 1) {
				if (onepan[i][0] == 0 || onepan[i][j] == 0)
					continue;
				if (abs(onepan[i][0] == abs(onepan[i][j]))) {
					if (onepan[i][0] > 0) onepan[i][0] *= -1;
					if (onepan[i][j] > 0) onepan[i][j] *= -1;
					found = true;
				}
			}
			else {
				if (onepan[i][j] == 0 || onepan[i][j + 1] == 0)
					continue;
				if (abs(onepan[i][j] == abs(onepan[i][j + 1]))) {
					if (onepan[i][j] > 0) onepan[i][j] *= -1;
					if (onepan[i][j + 1] > 0) onepan[i][j + 1] *= -1;
					found = true;
				}
			}
		}
	}

	// 위 아래
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (onepan[i][j] == 0 || onepan[i + 1][j] == 0)
				continue;
			if (abs(onepan[i][j]) == abs(onepan[i + 1][j])) {
				if (onepan[i][j] > 0) onepan[i][j] *= -1;
				if (onepan[i + 1][j] > 0) onepan[i + 1][j] *= -1;
				found = true;
			}
		}
	}

	if (found) { // 같은 것 있으면 지우기
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < m; j++)
				if (onepan[i][j] < 0)
					onepan[i][j] = 0;
	}
	else { // 같은 것 없으면 평균 구해서 +-
		double cnt = 0;
		double sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (onepan[i][j] > 0) {
					cnt++;
					sum += onepan[i][j];
				}
			}
		}

		double avg = sum / cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (onepan[i][j] > avg && onepan[i][j] > 0)
					onepan[i][j] -= 1;
				else if(onepan[i][j] < avg && onepan[i][j] > 0)
					onepan[i][j] += 1;
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			onepan[i].push_back(input);
		}
	}
		
	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		int baesu = x;
		while (1) {
			if (baesu > n) break;
			turn(baesu, d, k);
			baesu += x;
		}
		deleteNum();
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			if (onepan[i][j] > 0)
				ans += onepan[i][j];
	cout << ans << "\n";

	return 0;
}
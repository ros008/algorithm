#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, d, ans = 0;
int map[16][16];
int mapCopied[16][16];
int archer[3];

vector<pair<pair<int, int>, int>> enemy; // isdead = 0  0산것 1죽은것
vector<pair<pair<int, int>, int>> enemyCopied;

void copyMap() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mapCopied[i][j] = map[i][j];
}

void print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mapCopied[i][j] << " ";
		}
		cout << "\n";
	}
}

void moveEnemy() {
	int s = enemyCopied.size();
	for (int i = s - 1; i >= 0 ; i--) {
		if (enemyCopied[i].second == 1) continue;
		int x = enemyCopied[i].first.first;
		int y = enemyCopied[i].first.second;

		mapCopied[x][y] = 0;
		if (x < n - 1) {
			mapCopied[x + 1][y] = 1;
			enemyCopied[i].first.first += 1;
		}
		else 
			enemyCopied[i].second = 1;
	}
}

bool isAllKilled() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mapCopied[i][j] == 1) 
				return false;
	return true;
}

bool comp(pair<pair<int, int>, pair<int, int>> A, pair<pair<int, int>, pair<int, int>> B) {
	if (A.second.first == B.second.first)
		return A.first.second < B.first.second;
	else
		return A.second.first < B.second.first;
}

void getInput() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				enemy.push_back({ {i,j}, 0 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	getInput();

	vector<int> archers;
	for (int i = 0; i < m - 3; i++)
		archers.push_back(0);
	for (int i = 0; i < 3; i++)
		archers.push_back(1);

	do{
		int cnt = 0;
		copyMap();
		enemyCopied = enemy;

		for (int i = 0, j = 0; i < m; i++)
			if (archers[i] == 1)
				archer[j++] = i;

		while (1) {
			if (isAllKilled())
				break;

			pair<pair<int, int>, int> target[3];

			for (int i = 0; i < 3; i++) {
				vector<pair<pair<int, int>, pair<int, int>>> toKill; // x, y, 거리

				// 거리 구하기
				int archerX = n;
				int archerY = archer[i];
				
				for (int j = 0; j < enemyCopied.size(); j++) {
					if (enemyCopied[j].second == 0) {
						int tmpDist = abs(archerX - enemyCopied[j].first.first) + abs(archerY - enemyCopied[j].first.second);
						if (tmpDist <= d) {
							toKill.push_back({ {enemyCopied[j].first.first, enemyCopied[j].first.second}, {tmpDist, j} });
						}
					}
				}

				if (toKill.size() > 1) {
					sort(toKill.begin(), toKill.end(), comp);
					target[i].first.first = toKill[0].first.first;
					target[i].first.second = toKill[0].first.second;
					target[i].second = toKill[0].second.second;
				}
				else if (toKill.size() == 1) {
					target[i].first.first = toKill[0].first.first;
					target[i].first.second = toKill[0].first.second;
					target[i].second = toKill[0].second.second;
				}
				else {
					target[i].first.first = -1;
					target[i].first.second = -1;
					target[i].second = -1;
				}
			}

			for (int i = 0; i < 3; i++) {
				int x = target[i].first.first;
				int y = target[i].first.second;
				int idx = target[i].second;

				mapCopied[x][y] = 0;

				if (x == -1 && y == -1) continue;
				if (enemyCopied[idx].second != 1) {
					enemyCopied[idx].second = 1;
					cnt++;
				}
			}

			moveEnemy();
			//print();
		}
		ans = max(ans, cnt);
	} while (next_permutation(archers.begin(), archers.end()));

	cout << ans << "\n";

	return 0;
}
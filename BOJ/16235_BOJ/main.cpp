#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };

int N, M, K;
int ans = 0;
vector<int> treeMap[11][11]; // 나이 적힘 0은 나무 없음
int yangboon[11][11]; // 양분이 적힘
int A[11][11];

void SpringAndSummer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (treeMap[i][j].size() == 0) continue;
			int deadEnergy = 0;
			vector<int> tmp;
			sort(treeMap[i][j].begin(), treeMap[i][j].end());
			for (int k = 0; k < treeMap[i][j].size(); k++) {
				int age = treeMap[i][j][k];
				if (yangboon[i][j] >= age) {
					yangboon[i][j] -= age;
					tmp.push_back(age + 1);
				}
				else {
					deadEnergy += (age / 2);
				}
			}

			treeMap[i][j].clear();
			for (int k = 0; k < tmp.size(); k++)
				treeMap[i][j].push_back(tmp[k]);
			yangboon[i][j] += deadEnergy;
		}
	}
}

void Fall() {
	// 가을
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (treeMap[i][j].size() == 0) continue;
			for (int s = 0; s < treeMap[i][j].size(); s++) {
				int age = treeMap[i][j][s];
				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
							treeMap[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void Winter() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			yangboon[i][j] += A[i][j];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			yangboon[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		treeMap[x - 1][y - 1].push_back(z);
	}

	for (int year = 0; year < K; year++) {
		SpringAndSummer();
		Fall();
		Winter();
	}

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			ans += treeMap[i][j].size();

	cout << ans << "\n";

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int N, maxScore = 0;
int iningResult[50 + 1][9 + 1]; // i번째 이닝에서 j번 선수가 얻는 결과
int order[9 + 1];
bool selected[9 + 1];

void startGame() {
	int score = 0;
	int baseState[4];
	int battingOrder = 1;

	for (int i = 1; i <= N; i++) { // N 이닝 동안
		int outCnt = 0;
		memset(baseState, 0, sizeof(baseState));
		bool nextIning = false;

		while (1) {
			for (int j = battingOrder; j <= 9; j++) {
				int batResult = iningResult[i][order[j]];
				if (batResult == 0) outCnt++;
				else if (batResult == 1) {
					for (int k = 3; k >= 1; k--) {
						if (baseState[k] == 1) {
							if (k == 3) {
								score++;
								baseState[k] = 0;
							}
							else {
								baseState[k + 1] = 1;
								baseState[k] = 0;
							}
						}
					}
					baseState[1] = 1;
				}
				else if (batResult == 2) {
					for (int k = 3; k >= 1; k--) {
						if (baseState[k] == 1) {
							if (k == 3 || k == 2) {
								score++;
								baseState[k] = 0;
							}
							else {
								baseState[k + 2] = 1;
								baseState[k] = 0;
							}
						}
					}
					baseState[2] = 1;
				}
				else if (batResult == 3) {
					for (int k = 3; k >= 1; k--) {
						if (baseState[k] == 1) {
							score++;
							baseState[k] = 0;
						}
					}
					baseState[3] = 1;
				}
				else if (batResult == 4) {
					for (int k = 3; k >= 1; k--) {
						if (baseState[k] == 1) {
							score++;
							baseState[k] = 0;
						}
					}
					score++;
				}

				if (outCnt == 3) {
					battingOrder = j + 1;
					if (battingOrder == 10) battingOrder = 1;
					nextIning = true;
					break;
				}
			}
			if (nextIning) break;
			battingOrder = 1;
		}
	}

	maxScore = max(maxScore, score);
}

void dfs(int cnt) {
	if (cnt == 10) {
		startGame();
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (selected[i] == true) continue;
		selected[i] = true;
		order[i] = cnt;
		dfs(cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 9; j++)
			cin >> iningResult[i][j];

	selected[4] = true;
	order[4] = 1;
	dfs(2); // 2번 선수부터

	cout << maxScore << "\n";

	return 0;
}
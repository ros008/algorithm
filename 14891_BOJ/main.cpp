#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <cstring>
#include <cmath>

using namespace std;

int k;
deque<int> tobni[5];
int rotateDir[5];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 4; i++) {
		string input; cin >> input;
		for (int j = 0; j < 8; j++) {
			tobni[i].push_back(input[j] - '0');
		}
	}

	cin >> k;
	while (k--) {
		int tobniNum, dir, idx;
		cin >> tobniNum >> dir;
		memset(rotateDir, 0, sizeof(rotateDir));

		rotateDir[tobniNum] = dir;

		//left
		idx = tobniNum - 1;
		while (idx >= 1) {
			if (tobni[idx][2] == tobni[idx + 1][6]) 
				break;
	
			rotateDir[idx] = (-1 * rotateDir[idx + 1]);
			idx--;
		}

		// right
		idx = tobniNum + 1;
		while (idx <= 4) {
			if (tobni[idx][6] == tobni[idx - 1][2])
				break;

			rotateDir[idx] = (-1 * rotateDir[idx - 1]);
			idx++;
		}

		// rotate
		for (int i = 1; i <= 4; i++) {
			if (rotateDir[i] == 1) { // clockwise
				int tmp = tobni[i].back();
				tobni[i].pop_back();
				tobni[i].push_front(tmp);
			}
			else if (rotateDir[i] == -1) {
				int tmp = tobni[i].front();
				tobni[i].pop_front();
				tobni[i].push_back(tmp);
			}
		}
	}

	int score = 0;
	for (int i = 1; i <= 4; i++) {
		if (tobni[i][0] == 1) score += pow(2, i - 1);
	}

	cout << score << "\n";

	return 0;
}
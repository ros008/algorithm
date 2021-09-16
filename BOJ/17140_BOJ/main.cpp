#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int r, c, k;
int A[101][101];
int rowSize = 3, colSize = 3; // row, col의 최대 사이즈 
int numCnt[101]; // 숫자 개수
int cnt = 0; // 반복 횟수

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> A[i][j];

	while (1) {
		if (A[r][c] == k)
			break;
		if (cnt > 100) {
			cnt = -1;
			break;
		}

		vector<int> maxSize;
		if (rowSize >= colSize) { // 가로 정렬
			for (int i = 1; i <= rowSize; i++) {
				vector<pair<int, int>> v; // 개수, 숫자
				memset(numCnt, 0, sizeof(numCnt));
				for (int j = 1; j <= colSize; j++) 
					numCnt[A[i][j]]++;

				for (int j = 1; j <= 100; j++) {
					if (numCnt[j] == 0) continue;
					v.push_back({ numCnt[j], j });
				}
				sort(v.begin(), v.end());
				for (int j = 1; j <= colSize; j++) 
					A[i][j] = 0;
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					A[i][idx++] = v[j].second;
					A[i][idx++] = v[j].first;
				}
				idx--;
				maxSize.push_back(idx);
			}
			sort(maxSize.begin(), maxSize.end());
			colSize = maxSize.back();
		}
		else { // 세로 정렬
			for (int j = 1; j <= colSize; j++) {
				vector<pair<int, int>> v; // 개수, 숫자
				memset(numCnt, 0, sizeof(numCnt));
				for (int i = 1; i <= rowSize; i++) 
					numCnt[A[i][j]]++;

				for (int i = 1; i <= 100; i++) {
					if (numCnt[i] == 0) continue;
					v.push_back({ numCnt[i], i });
				}
				sort(v.begin(), v.end());
				for (int i = 1; i <= rowSize; i++)
					A[i][j] = 0;
				int idx = 1;
				for (int i = 0; i < v.size(); i++) {
					A[idx++][j] = v[i].second;
					A[idx++][j] = v[i].first;
				}
				idx--;
				maxSize.push_back(idx);
			}
			sort(maxSize.begin(), maxSize.end());
			rowSize = maxSize.back();
		}

		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}
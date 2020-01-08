#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int N;
char maeulMap[50][50];
int height[50][50];

queue<pair<int, int>> q;
pair<int, int> startPos;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maeulMap[i][j];
			if (maeulMap[i][j] == 'K') {
				q.push(make_pair(i, j));
			}
			else if (maeulMap[i][j] == 'P') {
				startPos.first = i;
				startPos.second = j;
			}
		}
	}


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> height[i][j];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	Input();


	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define INF 987654321

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int R, C, N;
char map[101][101];
vector<int> makdae;
vector<pair<int, int>> risingCluster;
bool cluster[101][101];
bool visited[101][101];

bool throwMakdae(int h, char dir) {
	if (dir == 'L') {
		for (int i = 0; i < C; i++) {
			if (map[h][i] == 'x') {
				map[h][i] = '.';
				return true;
			}
		}
	}
	else if (dir == 'R') {
		for (int i = C - 1; i >= 0; i--) {
			if (map[h][i] == 'x') {
				map[h][i] = '.';
				return true;
			}
		}
	}

	return false;
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (map[nx][ny] == 'x' && !visited[nx][ny]) {
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
	}
}

bool findCluster() {
	bool ret = false;

	for (int i = 0; i < C; i++) {
		if (map[R - 1][i] == 'x' && visited[R - 1][i] == false) {
			bfs(R - 1, i);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'x' && visited[i][j] == false) {
				ret = true;
				risingCluster.push_back({ i,j });
				cluster[i][j] = true;
			}
		}
	}

	return ret;
}

int howMuchDown(int x, int y) {
	int cnt = 0;
	for (int i = x + 1; i < R; i++) {
		if (map[i][y] == 'x') {
			if (cluster[i][y] == true) return INF;
			else return cnt;
		}
		else if (map[i][y] == '.') cnt++;
	}
	return cnt;
}

void makeMap() {
	int h = INF - 1;
	for (int i = 0; i < risingCluster.size(); i++) {
		int x = risingCluster[i].first;
		int y = risingCluster[i].second;

		int tmpH = howMuchDown(x, y);
		if (tmpH == INF) continue;
		else h = min(h, tmpH);
	}

	sort(risingCluster.begin(), risingCluster.end());
	for (int i = risingCluster.size() - 1; i >= 0; i--) {
		int x = risingCluster[i].first;
		int y = risingCluster[i].second;

		map[x][y] = '.';
		map[x + h][y] = 'x';
	}
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << map[i][j];
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input; 
		cin >> input;
		makdae.push_back(input);
	}

	for (int i = 0; i < makdae.size(); i++) {
		risingCluster.clear();
		memset(visited, false, sizeof(visited));
		memset(cluster, false, sizeof(cluster));

		char dir;
		if (i % 2 == 0) dir = 'L';
		else dir = 'R';

		if (throwMakdae(R - makdae[i], dir) == false) {
			continue;
		}
			
		if (findCluster() == false) {
			continue;
		}
		else makeMap();
	}

	print();

	return 0;
}
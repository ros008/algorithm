#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int n, m;
int map[1001][1001];
bool visited[1001][1001];
int maxSize = 0;
int mapSize[1000001];
vector<pair<int, int>> zeroV;

void bfs(int a, int b, int idx) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	map[a][b] = idx;
	int shapeSize = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] || map[nx][ny] == 0) continue;

			shapeSize++;
			q.push({ nx, ny });
			visited[nx][ny] = true;
			map[nx][ny] = idx;
		}
	}

	mapSize[idx] = shapeSize;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				zeroV.push_back({ i,j });
		}
	}
		
	int num = 1;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (map[i][j] == 1 && !visited[i][j]) 
				bfs(i, j, num++);	

	for (int i = 0; i < zeroV.size(); i++) {
		set<int> s;

		int x = zeroV[i].first;
		int y = zeroV[i].second;
		int tmpSize = 1;

		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0) continue;

			if (s.find(map[nx][ny]) == s.end()) {
				s.insert(map[nx][ny]);
				tmpSize += mapSize[map[nx][ny]];
			}
		}
		maxSize = max(maxSize, tmpSize);
	}

	cout << maxSize << "\n";

	return 0;
}
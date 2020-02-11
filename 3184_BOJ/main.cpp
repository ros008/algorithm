#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int r, c;
char madang[251][251];
bool visited[251][251];
int totalY = 0, totalN = 0;

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	
	int yang = 0; 
	int neuk = 0;
	
	if (madang[a][b] == 'v') neuk++;
	else if (madang[a][b] == 'o') yang++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (visited[nx][ny]) continue;
			if (madang[nx][ny] == '#') continue;

			if (madang[nx][ny] == 'v') neuk++;
			else if (madang[nx][ny] == 'o') yang++;

			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}

	if (yang <= neuk) yang = 0;
	else neuk = 0;
	totalY += yang;
	totalN += neuk;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> madang[i][j];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j]) continue;
			if (madang[i][j] == '#') continue;
			bfs(i, j);
		}
	}
	
	cout << totalY << " " << totalN << "\n";

	return 0;
}
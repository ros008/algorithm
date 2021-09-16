#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>

#define INF 30*30*10000+1

using namespace std;

struct info {
	int from, to, cost;
};

vector<info> edge;
int map[31][31], hole[31][31];
int dist[31 * 31];

int dr[] = { 1, 0,-1,0 };
int dc[] = { 0,-1, 0,1 };


void bellman_ford() {


}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1) {
		int w, h;
		cin >> w >> h;
		
		if (w == 0 && h == 0) break;
		edge.clear();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = i * w + j;
				hole[i][j] = 0;
				dist[map[i][j]] = INF;
			}
		}
		// map에 1차원으로 변경한 값 넣기
		// dist는 1차원으로 변경된 것
		
		int g; // 묘비 위치
		cin >> g;
		for (int i = 0; i < g; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = -1;
		}

		int e; // 귀신 구멍의 위치
		cin >> e;
		for (int i = 0; i < e; i++) {
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			hole[y1][x1] = 1;
			edge.push_back({ map[y1][x1], map[y2][x2],t });
		}

		// edge에 귀신 구멍을 통한 이동을 포함한,
		// 모든 경로 집어 넣기
		// 출발지점이 묘비가 아니고 귀신구멍이 아니며
		// 도착지점이 범위를 벗어나지 않고 묘비가 아니어야 함.
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == -1 || hole[i][j]) 
					continue;
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (nr < 0 || nc < 0 || nr >= h || nc >= w || map[nr][nc] == -1) 
						continue;
					edge.push_back({ map[i][j], map[nr][nc], 1 });
				}
			}
		}

		// 벨만 포드 돌리기
		dist[0] = 0;
		int updated = 1;
		for (int v = 0; v < w*h - 1 - g && updated == 1; v++) {
			updated = 0;
			for (int i = 0; i < edge.size(); i++) {
				if (dist[edge[i].from] == INF) continue;
				if (edge[i].from == w * h - 1) continue;
				if (dist[edge[i].to] > dist[edge[i].from] + edge[i].cost) {
					updated = 1;
					dist[edge[i].to] = dist[edge[i].from] + edge[i].cost;
				}
			}
		}

		// 음의 사이클 찾기 위해 한번더 벨만 포드
		// 이때 거리의 변화가 있다면 음의 사이클 
		updated = 0;
		for (int i = 0; i < edge.size(); i++) {
			if (dist[edge[i].from] == INF) continue;
			if (edge[i].from == w * h - 1) continue;
			if (dist[edge[i].to] > dist[edge[i].from] + edge[i].cost) {
				updated = 1;
				break;
			}
		}
		

		if (updated == 1)
			cout << "Never\n";
		else if (dist[h*w - 1] == INF)
			cout << "Impossible\n";
		else
			cout << dist[h*w - 1] << "\n";
	}

	return 0;
}
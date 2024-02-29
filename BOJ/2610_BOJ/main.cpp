#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100 + 1;
const int INF = 987654321;

int N, M, groupNum = 0;
int dist[MAX][MAX];
vector<int> adj[MAX];
vector<int> ans;
bool visited[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if(i != j)
				dist[i][j] = INF;

	for (int i = 1; i <= N; i++)
		visited[i] = false;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++)
	//		cout << dist[i][j] << " ";
	//	cout << "\n";
	//}

	for (int i = 1; i <= N; i++) {
		vector<int> group;
		if (!visited[i]) {
			// 그룹 만들기
			queue<int> q;
			q.push(i);
			group.push_back(i);
			visited[i] = true;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				for (int i = 0; i < adj[cur].size(); i++) {
					int next = adj[cur][i];
					if (!visited[next]) {
						visited[next] = true;
						q.push(next);
						group.push_back(next);
					}
				}
			}

			// 그룹에서 의사전달시간 중 최댓값이, 최소가 되도록 대표 정하기
			int minT = INF, mIdx;
			for (int i = 0; i < group.size(); i++) {
				int tmpMax = 0;
				for (int j = 0; j < group.size(); j++) {
					if (tmpMax < dist[group[i]][group[j]]) {
						tmpMax = dist[group[i]][group[j]];
					}
				}
				if (tmpMax < minT) {
					minT = tmpMax;
					mIdx = group[i];
				}
			}
			ans.push_back(mIdx);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}
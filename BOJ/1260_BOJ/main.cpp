#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int bfsVisit[1001] = { 0, };
int dfsVisit[1001] = { 0, };
int dfsReVisit[1001] = { 0, };

stack<int> qq;

void bfs(vector<int> vec[], int v) {
	queue<int> qq;
	qq.push(v);
	bfsVisit[v] = 1;

	while (!qq.empty()) {
		int cur = qq.front();
		qq.pop();
		cout << cur << " ";

		for (int i = 0; i < vec[cur].size(); i++) {
			if (!bfsVisit[vec[cur][i]]) {
				bfsVisit[vec[cur][i]] = 1;
				qq.push(vec[cur][i]);
			}
		}
	}
}

void dfsRecursion(vector<int> vec[], int v) {
	dfsReVisit[v] = 1;
	cout << v << " ";

	for (int i = 0; i < vec[v].size(); i++) {
		if (!dfsReVisit[vec[v][i]]) {
			dfsRecursion(vec, vec[v][i]);
		}
	}
}

void dfsStack(vector<int> vec[], int v) {
	stack<int> ss;
	ss.push(v);
	dfsVisit[v] = 1;
	cout << v << " ";

	while (!ss.empty()) {
		int cur = ss.top();

		for (int i = 0; i < vec[cur].size(); i++) {
			if (!dfsVisit[vec[cur][i]]) {
				ss.push(vec[cur][i]);
				dfsVisit[vec[cur][i]] = 1;
				cout << vec[cur][i] << " ";
				break;
			}
			else if (i == vec[cur].size() - 1) {
				ss.pop();
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	vector<int> graph[N + 1];

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfsRecursion(graph, V);
	cout << "\n";
	bfs(graph, V);

	return 0;
}



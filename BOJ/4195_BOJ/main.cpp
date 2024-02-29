#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int MAX = 200000 + 2;

int parent[MAX];
int graphSize[MAX];

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

int Merge(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA != rootB) {
		parent[rootB] = rootA;
		graphSize[rootA] += graphSize[rootB];
		graphSize[rootB] = 1;
	}

	return graphSize[rootA];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int F;
		cin >> F;
		map<string, int> m;
		int idx = 0;

		for (int i = 0; i < 2 * F; i++) {
			parent[i] = i;
			graphSize[i] = 1;
		}
		for (int i = 0; i < F; i++) {
			string str1, str2;
			cin >> str1 >> str2;

			if (m.find(str1) == m.end()) 
				m.insert({ str1, idx++ });
			if (m.find(str2) == m.end()) 
				m.insert({ str2, idx++ });

			cout << Merge(m[str1], m[str2]) << "\n";
		}
	}

	return 0;
}
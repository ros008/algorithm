#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define INF 1900000000

using namespace std;

int n, m;
vector<long long> arr;

void buildTree(vector<long long>& minTree, vector<long long>& maxTree, int node, int s, int e) {
	if (s == e) {
		minTree[node] = arr[s];
		maxTree[node] = arr[s];
	}
	else {
		int mid = (s + e) / 2;
		buildTree(minTree, maxTree, node * 2, s, mid);
		buildTree(minTree, maxTree, node * 2 + 1, mid + 1, e);
		minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
		maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
	}	
}

long long maxQuery(vector<long long>& maxTree, int node, int s, int e, int a, int b) {
	if (b < s || e < a)
		return -INF;
	if (a <= s && e <= b)
		return maxTree[node];
	int mid = (s + e) / 2;
	long long left = maxQuery(maxTree, node * 2, s, mid, a, b);
	long long right = maxQuery(maxTree, node * 2 + 1, mid + 1, e, a, b);
	return max(left, right);
}

long long minQuery(vector<long long>& minTree, int node, int s, int e, int a, int b) {
	if (b < s || e < a)
		return INF;
	if (a <= s && e <= b)
		return minTree[node];
	int mid = (s + e) / 2;
	long long left = minQuery(minTree, node * 2, s, mid, a, b);
	long long right = minQuery(minTree, node * 2 + 1, mid + 1, e, a, b);
	return min(left, right);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int h = (int)ceil(log2(n));
	int treeSize = pow(2, h + 1);

	vector<long long> maxTree(treeSize + 1, -INF);
	vector<long long> minTree(treeSize + 1, INF);
	arr = vector<long long>(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	buildTree(minTree, maxTree, 1, 1, n);

	int b, c;
	for (int i = 1; i <= m; i++) {
		cin >> b >> c;
		cout << minQuery(minTree, 1, 1, n, b, c) << " " << maxQuery(maxTree, 1, 1, n, b, c) << "\n";
	}

	return 0;
}

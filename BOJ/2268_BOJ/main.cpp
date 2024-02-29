#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m;

ll updateTree(vector<ll> &tree, int node, int s, int e, int idx, int num) {
	if (idx < s || e < idx) 
		return tree[node];
	
	if (s == e) {
		tree[node] = num;
		return tree[node];
	}

	int mid = (s + e) / 2;
	ll left = updateTree(tree, node * 2, s, mid, idx, num);
	ll right = updateTree(tree, node * 2 + 1, mid + 1, e, idx, num);
	tree[node] = left + right;

	return tree[node];
}

ll getSum(vector<ll> &tree, int node, int s, int e, int left, int right) {
	if (right < s || e < left)
		return 0;

	if (left <= s && e <= right)
		return tree[node];

	int mid = (s + e) / 2;
	ll leftNode = getSum(tree, node * 2, s, mid, left, right);
	ll rightNode = getSum(tree, node * 2 + 1, mid + 1, e, left, right);
	
	return leftNode + rightNode;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int h = (int)ceil(log2(n)) + 1;
	int size = pow(2, h);

	vector<ll> arr(n + 1);
	vector<ll> tree(size + 1);

	while (m--) {
		int q;
		cin >> q;

		if (q == 0) {
			int i, j;
			cin >> i >> j;
			if (i > j) swap(i, j);
			cout << getSum(tree, 1, 1, n, i, j) << "\n";
		}
		else if (q == 1) {
			int i, k;
			cin >> i >> k;
			updateTree(tree, 1, 1, n, i, k);
		}
	}

	return 0;
}
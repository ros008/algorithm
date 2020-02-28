#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

void buildTree(vector<ll>& arr, vector<ll>& tree, int node, int s, int e) {
	if (s == e) {
		tree[node] = s;
	}
	else {
		int mid = (s + e) / 2;
		buildTree(arr, tree, node * 2, s, mid);
		buildTree(arr, tree, node * 2 + 1, mid + 1, e);
		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

int query(vector<ll> &arr, vector<ll> &tree, int node, int s, int e, int left, int right) {
	if (right < s || e < left) 
		return -1;

	if (left <= s && e <= right) 
		return tree[node];

	int mid = (s + e) / 2;
	int l = query(arr, tree, node * 2, s, mid, left, right);
	int r = query(arr, tree, node * 2 + 1, mid + 1, e, left, right);

	if (l == -1)
		return r;
	else if (r == -1)
		return l;
	else if (arr[l] < arr[r])
		return l;
	else
		return r;
}


ll getMaxArea(vector<ll> &arr, vector<ll> &tree, int s, int e) {
	int n = arr.size() - 1;
	int idx = query(arr, tree, 1, 1, n, s, e);

	ll area = (ll)(e - s + 1)*(ll)arr[idx];

	if (s < idx) {
		ll tmp = getMaxArea(arr, tree, s, idx - 1);
		area = max(area, tmp);
	}

	if (idx < e) {
		ll tmp = getMaxArea(arr, tree, idx + 1, e);
		area = max(area, tmp);
	}

	return area;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1) {
		int n;
		cin >> n;

		if (n == 0) break;

		int h = (int)ceil(log2(n)) + 1;
		int size = pow(2, h);

		vector<ll> tree(size + 1);
		vector<ll> arr(n + 1);

		for (int i = 1; i <= n; i++) 
			cin >> arr[i];
		
		buildTree(arr, tree, 1, 1, n);

		cout << getMaxArea(arr, tree, 1, n) << "\n";
	}

	return 0;
}
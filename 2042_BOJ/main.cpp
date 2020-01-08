#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 1000000

using namespace std;

int n, m, k;
vector<long long> arr;

void buildTree(vector<long long>& tree, int node, int s, int e) {
	if (s == e) {
		tree[node] = arr[s];
	}
	else {
		int mid = (e + s) / 2;
		buildTree(tree, node * 2, s, mid);
		buildTree(tree, node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

}

long long update(vector<long long>& tree, int node, int s, int e, int b, int c) {
	if (b < s || e < b) {
		return tree[node];
	}

	if (s == e) {
		tree[node] = c;
		return tree[node];
	}

	int mid = (e + s) / 2;
	long long left = update(tree, node * 2, s, mid, b, c);
	long long right = update(tree, node * 2 + 1, mid + 1, e, b, c);
	tree[node] = left + right;
	return tree[node];
}

long long getSum(vector<long long>& tree, int node, int s, int e, int b, int c) {
	if (c < s || e < b) {
		return 0;
	}
	if (b <= s && e <= c) {
		return tree[node];
	}
	int mid = (e + s) / 2;
	long long left = getSum(tree, node * 2, s, mid, b, c);
	long long right = getSum(tree, node * 2 + 1, mid + 1, e, b, c);
	return left + right;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> k;

	int h = (int)ceil(log2(n));
	int size = pow(2, h) * 2;

	vector<long long> tree(size + 1, 0);
	arr = vector<long long>(n + 1);

	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	
	buildTree(tree, 1, 1, n);

	//for (int i = 1; i <= size; i++) {
	//	cout << tree[i] << " ";
	//}

	int a, b;
	long long c;

	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			// b번째 수를 c로 바꾸기
			update(tree, 1, 1, n, b, c);
		}
		else {
			// b번째 수부터 c번째 수까지 합 구하기
			cout << getSum(tree, 1, 1, n, b, c) << "\n";
		}
	}

	return 0;
}

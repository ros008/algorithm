#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX_CANDY 1000000

using namespace std;

typedef long long ll;

long long candy[MAX_CANDY + 1] = { 0, };
long long result;
int size_tree;

void update(vector<ll>& tree, int idx, int s, int e, int pos, int diff) {
	if (pos < s || e < pos) return;
	tree[idx] += diff;
	if (s != e) {
		int mid = (s + e) / 2;
		update(tree, idx * 2, s, mid, pos, diff);
		update(tree, idx * 2 + 1, mid + 1, e, pos, diff);
	}
}

int query(vector<ll>& tree, int idx, int s, int e, int k) { // k번째 찾기
	if ((s == e) && result == 0) {
		cout << s << "\n";
		return s;
	}

	int mid = (s + e) / 2;

	if (result == 0 && (idx * 2 <= size_tree) && tree[idx * 2] >= k) {
		return result = query(tree, idx * 2, s, mid, k);
	}

	k -= tree[idx * 2];

	if (result == 0 && (idx * 2 + 1 <= size_tree) && tree[idx * 2 + 1] >= k) {
		return result = query(tree, idx * 2 + 1, mid + 1, e, k);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n;
	int a, b, c;

	int h = ceil(log2(MAX_CANDY));
	size_tree = pow(2, h) * 2;

	vector<ll> tree(size_tree);

	cin >> n;

	while (n--) {
		cin >> a;

		if (a == 1) {
			cin >> b;
			int idx = query(tree, 1, 1, MAX_CANDY, b);
			result = 0;
			update(tree, 1, 1, MAX_CANDY, idx, -1);
		}
		else {
			cin >> b >> c;
			update(tree, 1, 1, MAX_CANDY, b, c);
		}

	}

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int K, N;
	long long minTop = -1;
	cin >> K >> N;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int nums[101];
	
	for (int i = 0; i < K; i++) {
		cin >> nums[i];
		pq.push(nums[i]);
	}

	N--;
	while (N--) {
		minTop = pq.top();
		pq.pop();

		for (int i = 0; i < K; i++) {
			long long tmp = minTop * nums[i];
			pq.push(tmp);
			if (minTop % nums[i] == 0) break;
		}
	}

	cout << pq.top();

	return 0;
}

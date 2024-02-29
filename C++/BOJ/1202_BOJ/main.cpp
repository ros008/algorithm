#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> boseok[300001]; // 무게, 가격
int bag[300001];

int N, K;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> boseok[i].first;
		cin >> boseok[i].second;
	}
	
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}

	sort(boseok, boseok + N);
	sort(bag, bag + K);
	
	priority_queue<int> val;
	long long result = 0;
	for (int i = 0, j = 0; i < K; i++) {
		while (j < N && boseok[j].first <= bag[i]) {
			val.push(boseok[j].second);
			j++;
		}
		if (!val.empty()) {
			result += val.top();
			val.pop();
		}
	}

	cout << result;

	return 0;
}
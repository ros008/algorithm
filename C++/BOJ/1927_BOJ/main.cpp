#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	int N, input;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input == 0) {
			if (pq.size() == 0) cout << 0 << "\n";
			else {
				cout<< pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}


	return 0;
}
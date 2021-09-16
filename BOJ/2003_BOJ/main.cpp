#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, cnt = 0, sum = 0;
	cin >> N >> M;

	vector<int> arr(N + 1);
	
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
		
	sum = arr[0];

	int start = 0, end = 0;
	
	while (start <= end && end < N) {
		if (sum < M) {
			end++;
			sum += arr[end];
		}
		else if (sum == M) {
			cnt++; end++;
			sum += arr[end];
		}
		else if (sum > M) {
			sum -= arr[start];
			start++;
		}

		if (start > end && start < N) {
			end = start;
			sum = arr[start];
		}
	}

	cout << cnt;

	return 0;
}
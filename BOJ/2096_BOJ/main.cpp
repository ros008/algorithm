#include <iostream>
#include <algorithm>

using namespace std;

int N;
int input[3] = { 0, };
int minDP[3] = { 0, };
int maxDP[3] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	cin >> input[0] >> input[1] >> input[2];
	for (int i = 0; i < 3; i++)
		minDP[i] = maxDP[i] = input[i];

	int tmp0, tmp1, tmp2;

	for (int i = 1; i < N; i++) {
		cin >> input[0] >> input[1] >> input[2];
		
		tmp0 = minDP[0]; tmp1 = minDP[1]; tmp2 = minDP[2];
		minDP[0] = min(tmp0, tmp1) + input[0];
		minDP[1] = min(min(tmp0, tmp1), tmp2) + input[1];
		minDP[2] = min(tmp1, tmp2) + input[2];

		tmp0 = maxDP[0]; tmp1 = maxDP[1]; tmp2 = maxDP[2];
		maxDP[0] = max(tmp0, tmp1) + input[0];
		maxDP[1] = max(max(tmp0, tmp1), tmp2) + input[1];
		maxDP[2] = max(tmp1, tmp2) + input[2];
	}

	cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << " ";
	cout << min(min(minDP[0], minDP[1]), minDP[2]) << " ";

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int W[101], V[101];
int volume[100001];

void dp() {
	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			if (W[i] <= j) {
				volume[j] = max(volume[j], volume[j - W[i]] + V[i]);
			}
		}
	}

	cout << volume[K];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	dp();

	return 0;
}
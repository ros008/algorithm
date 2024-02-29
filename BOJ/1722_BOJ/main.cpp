#include <iostream>
#include <vector>

using namespace std;

long long f[21];
bool chk[21];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, qNum;
	cin >> n;

	f[0] = 1;
	for (int i = 1; i <= 20; i++) {
		f[i] = f[i - 1] * i;
	}

	cin >> qNum;
	if (qNum == 1) { // k��°�� �� ���ϱ�
		long long k;
		cin >> k;

		for (int i = 0; i < n; i++) { // i��° ����
			for (int j = 1; j <= n; j++) { // j ���� �ĺ�
				if (chk[j]) continue;
				if (k <= f[n - (i + 1)]) {
					cout << j << " ";
					chk[j] = true;
					break;
				}
				else {
					k -= f[n - (i + 1)];
				}
			}
		}
	}
	else if (qNum == 2) { // �־��� ���� ���°���� ���ϱ�
		long long order = 0;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j < arr[i]; j++) {
				if (!chk[j]) {
					order = order + f[n - (i + 1)];
				}
			}
			chk[arr[i]] = true;
		}
		cout << order + 1;
	}

	return 0;
}
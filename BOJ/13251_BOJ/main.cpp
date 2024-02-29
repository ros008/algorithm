#include <iostream>

using namespace std;

int input[51];
double johab[51];
int total = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int m, k;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> input[i];
		total += input[i];
	}
	
	cin >> k;
	double tmp;
	for (int i = 0; i < m; i++) {
		if (input[i] >= k) {
			tmp = 1.0;
			for (int j = 0; j < k; j++) {
				tmp = tmp * (input[i] - j) / (total - j);
			}
			johab[i] += tmp;
		}
	}
	
	double result = 0.0;
	for (int i = 0; i < m; i++) {
		//cout << johab[i] << " ";
		result += johab[i];
	}

	cout << fixed;
	cout.precision(10);
	cout << result << "\n";

	return 0;
}
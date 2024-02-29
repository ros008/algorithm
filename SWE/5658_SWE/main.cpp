#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int N, K;
		deque<int> dq;
		vector<int> v;

		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			char input;
			cin >> input;
			if (input >= 'A') {
				dq.push_back(10 + input - 'A');
			}
			else {
				dq.push_back(input - '0');
			}
		}

		int len = N / 4; // 한변의 숫자 개수

		for (int k = 0; k < len; k++) { // 회전 횟수
			for (int i = 0; i < 4; i++) { 
				int sum = 0; 
				for (int j = 0; j < len; j++) {
					int tmp = dq[i * len + j];
					tmp *= pow(16, len - 1 - j);
					sum += tmp;
				}
				bool flag = true;
				for (int i = 0; i < v.size(); i++) {
					if (v[i] == sum) {
						flag = false;
						break;
					}
				}
				if(flag) v.push_back(sum);
			}

			// 회전
			dq.push_front(dq.back());
			dq.pop_back();
		}

		sort(v.begin(), v.end(), greater<int>());

		cout << "#" << T << " " << v[K - 1] << "\n";
	}

	return 0;
}
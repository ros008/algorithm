// 문제 이해가 전혀 안된다!!

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int inputNum[2000][500];
 

int main() {

	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++) {

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> inputNum[N][M];
			}
		}




		cout << "#" << " " << k << "" << endl;
	}

	return 0;
}
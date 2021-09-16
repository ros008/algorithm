#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 스위치를 누르는 순서는 상관 없음. 
// 스위치를 누르는 횟수가 상관 있음.
int arr[16];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; 
	cin >> T;
	
	while (T--) {
		for (int i = 0; i <= 15; i++)
			cin >> arr[i];

	}

	return 0;
}
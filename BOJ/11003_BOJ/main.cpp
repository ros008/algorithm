#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, L, input;
	cin >> N >> L;
	deque<pair<int, int>> dq; // 숫자, 인덱스값

	for (int i = 0; i < N; i++) {
		// 오래된것 없애기
		while(dq.size() > 0 && i - dq.front().second >= L) 	
			dq.pop_front();
			
		// 입력 받기
		cin >> input;

		// deque 뒤에 입력 값보다 큰 것 빼기
		while (dq.size() > 0 && dq.back().first >= input)
			dq.pop_back();

		dq.push_back(make_pair(input, i));
		cout << dq.front().first << " ";
	}


	return 0;
}
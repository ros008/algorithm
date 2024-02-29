#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, L, input;
	cin >> N >> L;
	deque<pair<int, int>> dq; // ����, �ε�����

	for (int i = 0; i < N; i++) {
		// �����Ȱ� ���ֱ�
		while(dq.size() > 0 && i - dq.front().second >= L) 	
			dq.pop_front();
			
		// �Է� �ޱ�
		cin >> input;

		// deque �ڿ� �Է� ������ ū �� ����
		while (dq.size() > 0 && dq.back().first >= input)
			dq.pop_back();

		dq.push_back(make_pair(input, i));
		cout << dq.front().first << " ";
	}


	return 0;
}
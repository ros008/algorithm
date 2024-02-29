#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main() {

	int tc;
	//cin >> tc;
	tc = 10;

	for (int t = 1; t <= tc; t++) {

		int N;
		cin >> N;

		list<int> code;
		list<int> newCode;

		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			code.push_back(input);
		}

		int commandNum;
		cin >> commandNum;

		list<int>::iterator iter;

		for (int i = 0; i < commandNum; i++) {
			char com;
			int x;
			int y;

			cin >> com;
			cin >> x >> y;

			if (com == 'I') {
				for (int j = 0; j < y; j++) {
					int newIn;
					cin >> newIn;
					newCode.push_back(newIn);
				}

				iter = code.begin();
				for (int k = 0; k < x; k++) iter++;

				code.splice(iter, newCode);
			}
			else if (com == 'D') {

				iter = code.begin();
				for (int k = 0; k < x; k++) iter++;

				for (int j = 0; j < y; j++) {
					iter = code.erase(iter);
				}
			}

		}


		cout << "#" << t << " ";
		iter = code.begin();
		for (int i = 0; i < 10; i++, iter++) {
			cout << *iter << " ";
		}
		cout << "\n";
	}


	return 0;
}
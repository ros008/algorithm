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

		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			code.push_back(input);
		}

		int commandNum;
		cin >> commandNum;


		for (int i = 0; i < commandNum; i++) {
			char com;
			
			cin >> com;

			if (com == 'I') {
				int x, y;
				cin >> x >> y;

				list<int> newCode;

				for (int j = 0; j < y; j++) {
					int s;
					cin >> s;
					newCode.push_back(s);
				}

				list<int>::iterator iter;

				iter = code.begin();
				for (int k = 0; k < x; k++) iter++;

				code.splice(iter, newCode);
			}
			else if (com == 'D') {
				int x, y;
				cin >> x >> y;

				list<int>::iterator iter;

				iter = code.begin();
				for (int k = 0; k < x; k++) iter++;

				for (int j = 0; j < y; j++) {
					iter = code.erase(iter);
				}
			}
			else if (com == 'A') {
				int y;
				cin >> y;

				for (int j = 0; j < y; j++) {
					int s;
					cin >> s;
					code.push_back(s);
				}
			}
		}

		list<int>::iterator iter;

		cout << "#" << t << " ";

		iter = code.begin();
		for (int i = 0; i < 10; i++, iter++) {
			cout << *iter << " ";
		}
		cout << "\n";
	}


	return 0;
}
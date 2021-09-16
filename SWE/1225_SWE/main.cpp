#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int num[8];
int tc;

int main() {


	for (int k = 1; k <= 10; k++) {

		cin >> tc;


		for (int i = 0; i < 8; i++) {
			cin >> num[i];
		}

		int tmp;
		int index = 1;

		while (1) {
			if (index > 5)
				index = 1;
			
			if (num[0] - index > 0) {
				tmp = num[0] - index;
				for (int i = 1; i < 8; i++) {
					num[i - 1] = num[i];
				}
				num[7] = tmp;
			}
			else {
				tmp = 0;
				for (int i = 1; i < 8; i++) {
					num[i - 1] = num[i];
				}
				num[7] = tmp;
				break;
			}

			index++;
		}


		cout << "#" << k << " ";
		for (int i = 0; i < 8; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
	}


	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;

char arr[10][4] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int numcnt[10];

int tc;
string tmp;
int len;


int main() {

	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		cin >> tmp;
		cin >> len;
		
		for (int i = 0; i < len; i++) {
			
			char num[4];
			cin >> num;

			for (int j = 0; j < 10; j++) {
				if (!strcmp(num, arr[j])) {
					numcnt[j]++;
					break;
				}
			}
		}



		cout << "#" << t << " ";
		for (int i = 0; i < 10; i++) {
			for (int n = 0; n < numcnt[i]; n++) {
				cout << arr[i] << " ";
			}
			numcnt[i] = 0;
		}
		cout << "\n";
	}


	return 0;
}
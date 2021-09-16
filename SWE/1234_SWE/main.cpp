#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int len;
string code;

int main() {
	
	for (int tc = 1; tc <= 10; tc++) {

		cin >> len;
		cin >> code;
	
		int start = 0;

		int i = 0;
		while(i < len) {
			if (code[i] == code[i + 1]) {
				code.erase(i, 2);
				len -= 2;
				i = 0;
				continue;
			}
			i++;
		}


		cout << "#" << tc << " " << code << "\n";
	}
	
	
	return 0;
}
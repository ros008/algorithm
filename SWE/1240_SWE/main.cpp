#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string code[10] = {
	"0001101", // 0
	"0011001", // 1
	"0010011", // 2
	"0111101", // 3
	"0100011", // 4
	"0110001", // 5
	"0101111", // 6
	"0111011", // 7
	"0110111", // 8
	"0001011"  // 9
};

int tc;
int N, M;
int last_index = 0;
int first_index = 0;
int odd = 0;
int even = 0;
int veriCode = 0;
int flag = 0;
string str;
string codeStr;

int main() {

	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		
		cin >> N >> M;
		
		last_index = 0;
		first_index = 0;
		even = 0;
		odd = 0;
		veriCode = 0;
		flag = 0;
		

		// 배열 입력 받아서 코드의 가장 마지막 index 값 알아내기
		for (int i = 0; i < N; i++) {
			cin >> str;
			for (int j = str.length() - 1; j >= 0; j--) {
				if (str[j] == '1' && flag == 0) {
					last_index = j;
					first_index = last_index - 55;
					codeStr = str.substr(first_index, 56);
					flag = 1;

					break;
				}
			}
		}

		for (int i = 0;i < 8; i++) {
			for (int j = 0; j < 10; j++) {
				if (codeStr.substr(7 * i, 7) == code[j]) {
					if (i == 7) veriCode = j;
					else if (i % 2 == 0) even += j;
					else odd += j;
					break;
				}
			}
		}

		if ((even * 3 + odd + veriCode) % 10 == 0) {
			cout << "#" << k << " " << even + odd + veriCode << "\n";
		}
		else {
			cout << "#" << k << " " << "0" << "\n";
		}

	}

	return 0;
}
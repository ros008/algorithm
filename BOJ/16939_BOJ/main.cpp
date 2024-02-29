#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cube[25];
int cubeCopied[25];
bool ans;

bool checkColor() {
	for (int k = 0; k < 6; k++) 
		for (int i = 1; i < 4; i++) 
			if (cubeCopied[k * 4 + i] != cubeCopied[k * 4 + i + 1])
				return false;

	return true;
}

void copyCube() {
	for (int i = 1; i <= 24; i++)
		cubeCopied[i] = cube[i];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int k = 1; k <= 24; k++)
		cin >> cube[k];
	
	int tmp;
	
	// 12가지
	// 앞 시계
	copyCube();
	tmp = cubeCopied[3];
	cubeCopied[3] = cubeCopied[16];
	cubeCopied[16] = cubeCopied[10];
	cubeCopied[10] = cubeCopied[17];
	cubeCopied[17] = tmp;

	tmp = cubeCopied[4];
	cubeCopied[4] = cubeCopied[14];
	cubeCopied[14] = cubeCopied[9];
	cubeCopied[9] = cubeCopied[19];
	cubeCopied[19] = tmp;

	tmp = cubeCopied[5];
	cubeCopied[5] = cubeCopied[7];
	cubeCopied[7] = cubeCopied[8];
	cubeCopied[8] = cubeCopied[6];
	cubeCopied[6] = tmp;

	if (checkColor()) {
		cout << 1 << "\n";
		return 0;
	}

	// 앞 반시계
	copyCube();

	tmp = cubeCopied[3];
	cubeCopied[3] = cubeCopied[17];
	cubeCopied[17] = cubeCopied[10];
	cubeCopied[10] = cubeCopied[16];
	cubeCopied[16] = tmp;

	tmp = cubeCopied[4];
	cubeCopied[4] = cubeCopied[19];
	cubeCopied[19] = cubeCopied[9];
	cubeCopied[9] = cubeCopied[14];
	cubeCopied[14] = tmp;

	tmp = cubeCopied[5];
	cubeCopied[5] = cubeCopied[6];
	cubeCopied[6] = cubeCopied[8];
	cubeCopied[8] = cubeCopied[7];
	cubeCopied[7] = tmp;

	if (checkColor()) {
		cout << 1 << "\n";
		return 0;
	}
	
	//// 뒤 시계
	//copyCube();

	//if (checkColor()) {
	//	cout << 1 << "\n";
	//	return 0;
	//}
	//
	//// 뒤 반시계
	//copyCube();

	//if (checkColor()) {
	//	cout << 1 << "\n";
	//	return 0;
	//}

	// 위 시계
	copyCube();
	tmp = cubeCopied[13];
	cubeCopied[13] = cubeCopied[5];
	cubeCopied[5] = cubeCopied[17];
	cubeCopied[17] = cubeCopied[21];
	cubeCopied[21] = tmp;

	tmp = cubeCopied[14];
	cubeCopied[14] = cubeCopied[6];
	cubeCopied[6] = cubeCopied[18];
	cubeCopied[18] = cubeCopied[22];
	cubeCopied[22] = tmp;

	tmp = cubeCopied[1];
	cubeCopied[1] = cubeCopied[3];
	cubeCopied[3] = cubeCopied[4];
	cubeCopied[4] = cubeCopied[2];
	cubeCopied[2] = tmp;

	if (checkColor()) {
		cout << 1 << "\n";
		return 0;
	}

	// 위 반시계
	copyCube();
	tmp = cubeCopied[13];
	cubeCopied[13] = cubeCopied[21];
	cubeCopied[21] = cubeCopied[17];
	cubeCopied[17] = cubeCopied[5];
	cubeCopied[5] = tmp;

	tmp = cubeCopied[14];
	cubeCopied[14] = cubeCopied[22];
	cubeCopied[22] = cubeCopied[18];
	cubeCopied[18] = cubeCopied[6];
	cubeCopied[6] = tmp;

	tmp = cubeCopied[1];
	cubeCopied[1] = cubeCopied[2];
	cubeCopied[2] = cubeCopied[4];
	cubeCopied[4] = cubeCopied[3];
	cubeCopied[3] = tmp;

	if (checkColor()) {
		cout << 1 << "\n";
		return 0;
	}

	//// 아래 시계
	//copyCube();

	//if (checkColor()) {
	//	cout << 1 << "\n";
	//	return 0;
	//}

	//// 아래 반시계
	//copyCube();
	//
	//if (checkColor()) {
	//	cout << 1 << "\n";
	//	return 0;
	//}

	// 왼 시계
	copyCube();
	tmp = cubeCopied[1];
	cubeCopied[1] = cubeCopied[24];
	cubeCopied[24] = cubeCopied[9];
	cubeCopied[9] = cubeCopied[5];
	cubeCopied[5] = tmp;

	tmp = cubeCopied[3];
	cubeCopied[3] = cubeCopied[22];
	cubeCopied[22] = cubeCopied[11];
	cubeCopied[11] = cubeCopied[7];
	cubeCopied[7] = tmp;

	tmp = cubeCopied[13];
	cubeCopied[13] = cubeCopied[15];
	cubeCopied[15] = cubeCopied[16];
	cubeCopied[16] = cubeCopied[14];
	cubeCopied[14] = tmp;

	if (checkColor()) {
		cout << 1 << "\n";
		return 0;
	}

	// 왼 반시계
	copyCube();
	tmp = cubeCopied[1];
	cubeCopied[1] = cubeCopied[5];
	cubeCopied[5] = cubeCopied[9];
	cubeCopied[9] = cubeCopied[24];
	cubeCopied[24] = tmp;

	tmp = cubeCopied[3];
	cubeCopied[3] = cubeCopied[7];
	cubeCopied[7] = cubeCopied[11];
	cubeCopied[11] = cubeCopied[22];
	cubeCopied[22] = tmp;

	tmp = cubeCopied[13];
	cubeCopied[13] = cubeCopied[14];
	cubeCopied[14] = cubeCopied[16];
	cubeCopied[16] = cubeCopied[15];
	cubeCopied[15] = tmp;

	if (checkColor()) {
		cout << 1 << "\n";
		return 0;
	}

	//// 오른 시계
	//copyCube();

	//if (checkColor()) {
	//	cout << 1 << "\n";
	//	return 0;
	//}

	//// 오른 반시계
	//copyCube();

	//if (checkColor()) {
	//	cout << 1 << "\n";
	//	return 0;
	//}

	cout << 0 << "\n";

	return 0;
}
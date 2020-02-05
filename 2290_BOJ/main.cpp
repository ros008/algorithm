#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int s;
string n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> s >> n;
	
	for (int h = 0; h < 2 * s + 3; h++) {
		for (int i = 0; i < n.length(); i++) {
			if (h == 0) {
				if (n[i] == '0' || n[i] == '2' || n[i] == '3' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9') {
					cout << " ";
					for (int i = 0; i < s; i++)
						cout << "-";
					cout << " ";
				}
				else {
					cout << " ";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << " ";
				}
				cout << " ";
			}
			else if (h >= 1 && h <= s) {
				if (n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '7') {
					cout << " ";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << "|";
				}
				else if (n[i] == '5' || n[i] == '6') {
					cout << "|";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << " ";
				}
				else if (n[i] == '0' || n[i] == '4' || n[i] == '8' || n[i] == '9') {
					cout << "|";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << "|";
				}
				cout << " ";
			}
			else if (h == s + 1) {
				if (n[i] == '0' || n[i] == '1' || n[i] == '7') {
					cout << " ";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << " ";
				}
				else if (n[i] == '2' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '8' || n[i] == '9') {
					cout << " ";
					for (int i = 0; i < s; i++)
						cout << "-";
					cout << " ";
				}
				cout << " ";
			}
			else if (h >= s + 2 && h <= 2 * s + 1) {
				if (n[i] == '1' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '7' || n[i] == '9') {
					cout << " ";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << "|";
				}
				else if (n[i] == '2') {
					cout << "|";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << " ";
				}
				else if (n[i] == '0' || n[i] == '6' || n[i] == '8') {
					cout << "|";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << "|";
				}
				cout << " ";
			}
			else if (h == 2 * s + 2) {
				if (n[i] == '1' || n[i] == '4' || n[i] == '7') {
					cout << " ";
					for (int i = 0; i < s; i++)
						cout << " ";
					cout << " ";
				}
				else if (n[i] == '0' || n[i] == '2' || n[i] == '3' || n[i] == '5' || n[i] == '6' || n[i] == '8' || n[i] == '9') {
					cout << " ";
					for (int i = 0; i < s; i++)
						cout << "-";
					cout << " ";
				}
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
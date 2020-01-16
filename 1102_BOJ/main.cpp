#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, p;
int baljeon[16][16];
int dp[16][16][1 << 16];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> baljeon[i][j];
	
	string onoff;
	cin >> onoff;

	int bitmask = 0;
	for (int i = 0; i < onoff.length(); i++)
		if (onoff[i] == 'Y')
			bitmask |= (1 << i);

	cin >> p;
	cout << bitmask;


	return 0;
}
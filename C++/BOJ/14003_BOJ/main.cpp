#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define MAX 1000000

using namespace std;

int arr[MAX + 1];
pair<int, int> input[MAX + 1];
stack<int> s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, pos, len = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> input[i].first;
		int pos = lower_bound(arr, arr + len, input[i].first) - arr;
		if (pos == len) 
			len++;

		arr[pos] = input[i].first;
		input[i].second = pos;

			
		//cout << input[i].first<< " " << input[i].second <<"\n";
	}
	
	cout << len << "\n";
	len--;
	for (int i = n; i > 0; i--) {
		if (input[i].second == len) {
			len--;
			s.push(input[i].first);
		}
		if (len == -1) break;
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
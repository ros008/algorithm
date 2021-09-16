#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	string input;
	int total = 0;
	map<string, int> m;
	map<string, int>::iterator iter;

	while (1) {
		getline(cin, input);
		
		if (input.size() == 0) break;
		
		total++;

		iter = m.find(input);
		if (iter != m.end()) {
			iter->second++;
		}
		else {
			m.insert(make_pair(input, 1));
		}
	}

	double per;

	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << fixed;
		cout.precision(4);
		per = 100 * iter->second / (double)total;
		cout << iter->first << " " << per << "\n";
	}

	return 0;
}

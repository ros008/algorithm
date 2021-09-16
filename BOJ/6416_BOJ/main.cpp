#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int a, b;
	int tc = 1;

	set<int> nodes;
	int line = 0;
	
	while (1) {
		
		cin >> a >> b;

		if (a < 0 && b < 0) break;
		
		if (a == 0 && b == 0) {
			if (line == 0 || nodes.size() == line + 1) {
				cout << "Case " << tc++ << " is a tree.\n";
			}
			else {
				cout << "Case " << tc++ << " is not a tree.\n";
			}
			nodes.clear();
			line = 0;
			continue;
		}
		nodes.insert(a);
		nodes.insert(b);
		line++;
	}


	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct meeting {
	int start;
	int end;
	meeting(int start, int end) : start(start), end(end) {};
};

bool cmp (meeting meeting1, meeting meeting2) {
	if (meeting1.end != meeting2.end) {
		return meeting1.end < meeting2.end;
	}
	else {
		return meeting1.start < meeting2.start;
	}
}

vector<meeting> meetings;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meetings.push_back(meeting(start, end));
	}

	sort(meetings.begin(), meetings.end(), cmp);
	
	int max_cnt = 0;
	int n = 0;

	for (int i = 0; i < meetings.size(); i++) {
		if (n <= meetings[i].start) {
			n = meetings[i].end;
			max_cnt++;
		}
	}

	cout << max_cnt << "\n";

	return 0;
}
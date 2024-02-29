#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int INF = 987654321;
const int MAX = 10 + 1;

// int nnn = 0;
int N, ans;
int map[MAX][MAX];
int stairSelect[MAX];
vector<pair<int, int>> people;
vector<pair<int, int>> stairs;

int dist(int peopleIdx, int stairIdx) {
	return abs(people[peopleIdx].first - stairs[stairIdx].first)
		+ abs(people[peopleIdx].second - stairs[stairIdx].second);
}

void goEat() {
	int lunchT = 0;
	for (int stairIdx = 0; stairIdx < 2; stairIdx++) {
		priority_queue<int, vector<int>, greater<int>> arriveTimeQ;
		queue<int> usingStairQ, waitingQ;

		int stairLen = map[stairs[stairIdx].first][stairs[stairIdx].second];

		for (int i = 0; i < people.size(); i++) {
			if (stairSelect[i] == stairIdx) {
				arriveTimeQ.push(dist(i, stairIdx));
			}
		}

		int curTime = 0;
		while (1) {
			if (arriveTimeQ.empty() && usingStairQ.empty() && waitingQ.empty())
				break;

			curTime++;

			// 계단에 있는 사람 처리
			while (usingStairQ.size() > 0) {
				if (usingStairQ.front() + stairLen == curTime)
					usingStairQ.pop();
				else
					break;
			}

			// 대기줄에 있는 사람 처리
			while (usingStairQ.size() < 3 && waitingQ.size() > 0) {
				usingStairQ.push(curTime);
				waitingQ.pop();
			}
			
			// 순서대로 오는 사람 처리
			while (arriveTimeQ.size() > 0 && curTime == arriveTimeQ.top()) {
				if (usingStairQ.size() == 3) {
					waitingQ.push(arriveTimeQ.top());
					arriveTimeQ.pop();
				}
				else {
					usingStairQ.push(arriveTimeQ.top() + 1);
					arriveTimeQ.pop();
				}
			}
		}
		lunchT = max(lunchT, curTime);
	}
	ans = min(ans,lunchT);
}

void dfs(int cnt) {
	if (cnt == people.size()) {
		goEat();
		/*cout << ++nnn << " ";
		for (int i = 0; i < people.size(); i++)
			cout << stairSelect[i] << " ";
		cout << "\n";*/
		return;
	}
	for (int i = 0; i < 2; i++) {
		stairSelect[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		ans = INF;
		people.clear();
		stairs.clear();

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					people.push_back({ i,j });
				else if (map[i][j] > 1)
					stairs.push_back({ i,j });
			}
		}
		dfs(0);

		cout << "#" << T << " " << ans << "\n";
	}
}
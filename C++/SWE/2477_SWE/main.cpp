#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

struct Person {
	int recNum;
	int repNum;
};

struct Node { //
	int idx;
	int time;
};

int N, M, K, A, B, ans;
int ai[11], bj[11], tk[1001];
Node receipt[11], repair[11]; // 접수, 정비에 누가 몇시에 들어갔는지
queue<int> receiptWaiting, repairWaiting; // 접수 대기, 정비 대기에 누가 들어 있는지
Person pinfo[1001]; // 사람들이 몇번 접수, 몇번 정비에서 했는지

void carCenter() {
	int cnt = 0; // A,B를 사용한 고객들의 합
	int t = 0; // 시간
	// 온사람 -> 접수 대기 -> 접수 -> 정비 대기 -> 정비 -> cnt
	while (1) {
		// 온사람 -> 접수 대기
		for (int i = 1; i <= K; i++) 
			if (tk[i] == t)
				receiptWaiting.push(i);
		
		// 접수 -> 정비 대기
		for (int i = 1; i <= N; i++) {
			if (receipt[i].idx != 0 && receipt[i].time == t) {
				repairWaiting.push({ receipt[i].idx });
				receipt[i].idx = 0;
			}
		}

		// 정비 -> cnt
		for (int i = 1; i <= M; i++) {
			if (repair[i].idx != 0 && repair[i].time == t) {
				repair[i].idx = 0;
				cnt++;
			}
		}

		// 접수 대기 -> 접수
		for (int i = 1; i <= N; i++) {
			if (receiptWaiting.empty()) break;
			if (receipt[i].idx == 0) {
				receipt[i].idx = receiptWaiting.front();
				receipt[i].time = t + ai[i];
				receiptWaiting.pop();
				pinfo[receipt[i].idx].recNum = i;
			}
		}
		// 정비 대기 -> 정비
		for (int i = 1; i <= M; i++) {
			if (repairWaiting.empty()) break;
			if (repair[i].idx == 0) {
				repair[i].idx = repairWaiting.front();
				repair[i].time = t + bj[i];
				repairWaiting.pop();
				pinfo[repair[i].idx].repNum = i;
			}
		}

		if (cnt >= K) {
			for (int i = 1; i <= K; i++) {
				if (pinfo[i].recNum == A && pinfo[i].repNum == B) {
					ans += i;
				}
			}
			break;
		}

		t++;
	}

	if (ans == 0) ans = -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		ans = 0;
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++)
			cin >> ai[i];
		for (int i = 1; i <= M; i++)
			cin >> bj[i];
		for (int i = 1; i <= K; i++)
			cin >> tk[i];

		carCenter();

		cout << "#" << T << " " << ans << "\n";

	}
	
	return 0;
}
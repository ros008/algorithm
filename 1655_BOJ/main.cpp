#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	priority_queue<int, vector<int>, less<int>> maxHeap; // 내림차
	priority_queue<int, vector<int>, greater<int>> minHeap; // 오름차
	
	int N, num;
	cin >> N;

	while(N--){
		cin >> num;
		if (maxHeap.size() > minHeap.size()) minHeap.push(num);
		else maxHeap.push(num);

		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int maxTop = maxHeap.top();
			int minTop = minHeap.top();
			
			maxHeap.pop();
			minHeap.pop();

			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}
		cout << maxHeap.top() << "\n";
	}

	return 0;
}

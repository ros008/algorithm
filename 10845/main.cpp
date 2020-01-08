#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>

#define MAX_SIZE 10000

using namespace std;

struct Queue {
	int arr[MAX_SIZE];
	int front; 
	int rear;
};

void QueueInit(Queue *sp) {
	sp->front = 0;
	sp->rear = -1;
}

int IsEmpty(Queue *sp) {
	if (sp->front == sp->rear + 1) return true;
	else return false;
}

int Size(Queue *sp) {
	return sp->rear - sp->front + 1;
}

void Push(Queue *sp, int data) {
	sp->arr[++(sp->rear)] = data;
}

int Pop(Queue *sp) {
	if (IsEmpty(sp)) return -1;
	return sp->arr[(sp->front)++];
}

int Front(Queue *sp) {
	if (IsEmpty(sp)) return -1;
	return sp->arr[(sp->front)];
}

int Back(Queue *sp) {
	if (IsEmpty(sp)) return -1;
	return sp->arr[sp->rear];
}

int main() {

	Queue queue;
	int N;
	char str[6];
	int num;

	cin >> N;

	QueueInit(&queue);

	for (int i = 0; i < N; i++) {

		cin >> str;
		if (strcmp(str, "push") == 0) {
			cin >> num;
			Push(&queue, num);
		}
		else if (strcmp(str, "pop") == 0) {
			cout << Pop(&queue) << "\n";
		}
		else if (strcmp(str, "size") == 0) {
			cout << Size(&queue) << "\n";
		}
		else if (strcmp(str, "empty") == 0) {
			cout << IsEmpty(&queue) << "\n";
		}
		else if (strcmp(str, "front") == 0) {
			cout << Front(&queue) << "\n";
		}
		else if (strcmp(str, "back") == 0){
			cout << Back(&queue) << "\n";
		}

	}

	return 0;
}
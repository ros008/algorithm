#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>

#define MAX_SIZE 10000

using namespace std;

struct Stack {
	int arr[MAX_SIZE];
	int top;
};

void StackInit(Stack *sp) {
	sp->top = -1;
}

int IsEmpty(Stack *sp) {
	if (sp->top == -1) return true;
	else return false;
}

int Size(Stack *sp) {
	return sp->top + 1;
}

int IsFull(Stack *sp) {
	if (sp->top + 1 >= MAX_SIZE) return true;
	else return false;
}

void Push(Stack *sp, int data) {
	if (IsFull(sp)) return;
	sp->arr[++(sp->top)] = data;
}

int Pop(Stack *sp) {
	if (IsEmpty(sp)) return -1;
	return sp->arr[(sp->top)--];
}

int Top(Stack *sp) {
	if (IsEmpty(sp)) return -1;
	return sp->arr[sp->top];
}

int main() {

	Stack stack;
	int N;
	char str[6];
	int num;

	cin >> N;

	StackInit(&stack);

	for (int i = 0; i < N; i++) {

		cin >> str;
		if (strcmp(str, "push") == 0) {
			cin >> num;
			Push(&stack, num);
		}
		else if (strcmp(str, "pop") == 0) {
			cout << Pop(&stack) << "\n";
		}
		else if (strcmp(str, "size") == 0) {
			cout << Size(&stack) << "\n";
		}
		else if (strcmp(str, "empty") == 0) {
			cout << IsEmpty(&stack) << "\n";
		}
		else if (strcmp(str, "top") == 0) {
			cout << Top(&stack) << "\n";
		}

	}

	return 0;
}
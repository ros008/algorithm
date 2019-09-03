#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct User {
	int age;
	char name[101];
};

bool compare(const User &a, const User &b) {
	return a.age < b.age;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;

	cin >> N;
	vector<User> info(N);

	for (int i = 0; i < N; i++) {
		cin >> info[i].age >> info[i].name;
	}

	stable_sort(info.begin(), info.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << info[i].age << " " << info[i].name << "\n";
	}

	return 0;
}
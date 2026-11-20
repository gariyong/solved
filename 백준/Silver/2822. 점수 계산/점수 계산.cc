#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Score {
	int score;
	int no;
}Score;


bool compare1(const Score& a, const Score& b) {
	return a.score > b.score;
}

bool compare2(const Score& a, const Score& b) {
	return a.no < b.no;
}

int main() {
	Score arr[8];
	int sum = 0;

	for (int i = 0; i < 8; i++) {
		cin >> arr[i].score;
		arr[i].no = i + 1;
	}
	sort(arr, arr+8, compare1);
	for (int i = 0; i < 5; i++) {
		sum += arr[i].score;
	}
	cout << sum << '\n';
	sort(arr, arr+5, compare2);
	for (int i = 0; i < 5; i++) {
		cout << arr[i].no << '\n';
	}

	return 0;
}
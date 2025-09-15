// 문제 : https://www.acmicpc.net/problem/27172
// 제목 : 수 나누기 게임

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> players(n);
	vector<int> scores(n, 0);
	vector<int> nums(MAX + 1, -1);

	for (int i = 0; i < n; i++) {
		cin >> players[i];
		nums[players[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		int x = players[i];

		for (int j = x * 2; j <= MAX; j += x) {
			if (nums[j] != -1) {
				scores[nums[j]]--;
				scores[i]++;
			}
		}
	}

	for (int score : scores) {
		cout << score << ' ';
	}

	return 0;
}
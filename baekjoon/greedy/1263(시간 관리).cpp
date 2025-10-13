// ¹®Á¦ : https://www.acmicpc.net/problem/1263
// Á¦¸ñ : ½Ã°£ °ü¸®

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Homework {
	int duration;
	int deadline;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Homework> homeworks(n);
	for (int i = 0; i < n; ++i) {
		cin >> homeworks[i].duration >> homeworks[i].deadline;
	}
	sort(homeworks.begin(), homeworks.end(), [](const Homework& a, const Homework& b) {
		return a.deadline < b.deadline;
		});

	int cur_time = homeworks[n - 1].deadline;
	for (int i = n - 1; i >= 0; i--) {
		auto& hw = homeworks[i];

		cur_time = min(cur_time, hw.deadline);
		cur_time -= hw.duration;
	}

	if (cur_time < 0) {
		cout << -1;
	}
	else {
		cout << cur_time;
	}

	return 0;
}

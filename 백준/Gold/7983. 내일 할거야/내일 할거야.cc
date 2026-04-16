#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct homework {
	int duration;
	int deadline;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<homework> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].duration >> v[i].deadline;
	}

	sort(v.begin(), v.end(), [](homework& a, homework& b) {
		return a.deadline > b.deadline;
		});

	int cur_time = v[0].deadline;
	for (homework cur : v) {
		cur_time = min(cur_time, cur.deadline);
		cur_time -= cur.duration;
	}

	cout << cur_time;

	return 0;
}
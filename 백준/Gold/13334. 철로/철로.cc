#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct people {
	int home;
	int office;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<people> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].home >> v[i].office;
		if (v[i].home > v[i].office) {
			swap(v[i].home, v[i].office);
		}
	}

	int L;
	cin >> L;

	sort(v.begin(), v.end(), [](const people& a, const people& b) {
		return a.office < b.office;
		});

	priority_queue<int, vector<int>, greater<int>> q;
	int res = 0;

	for (auto& x : v) {
		if (x.office - x.home > L) continue;

		q.push(x.home);
		while (!q.empty() && q.top() < x.office - L) {
			q.pop();
		}

		res = max(res, (int)q.size());
	}

	cout << res;

	return 0;
}
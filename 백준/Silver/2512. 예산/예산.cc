#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> buds(n);
	for (int i = 0; i < n; i++) cin >> buds[i];

	int gov_bud;
	cin >> gov_bud;

	int left = 0;
	int right = *max_element(buds.begin(), buds.end());
	int cap = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		long long sum = 0;
		for (int x : buds) {
			sum += min(x, mid);
		}

		if (sum <= gov_bud) {
			cap = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << cap;

	return 0;
}
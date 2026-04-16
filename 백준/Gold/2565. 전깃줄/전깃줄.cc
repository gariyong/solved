#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct elec_cable {
	int a;
	int b;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<elec_cable> cables(n);
	for (int i = 0; i < n; i++) {
		cin >> cables[i].a >> cables[i].b;
	}
	sort(cables.begin(), cables.end(), [](const elec_cable a, const elec_cable b) {
		return a.a < b.a;
		});

	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (cables[j].b < cables[i].b) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int result = n + 1;
	for (int i = 0; i < n; i++) {
		result = min(result, n - dp[i]);
	}

	cout << result;

	return 0;
}
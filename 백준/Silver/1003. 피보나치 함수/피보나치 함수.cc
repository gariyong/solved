#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int dp1[41];
	int dp0[41];
	int t;

	dp1[0] = 0;
	dp0[0] = 1;
	dp1[1] = 1;
	dp0[1] = 0;

	for (int i = 2; i <= 40; i++) {
		dp1[i] = dp1[i - 1] + dp1[i - 2];
		dp0[i] = dp0[i - 1] + dp0[i - 2];
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		int n; 
		cin >> n;

		cout << dp0[n] << ' ' << dp1[n] << '\n';
	}

	return 0;
}
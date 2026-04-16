#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long>menu(n);
	for (int i = 0; i < n; i++) {
		cin >> menu[i];
	}
	sort(menu.begin(), menu.end());

	vector<long long> pow2(n);
	pow2[0] = 1;
	for (int i = 1; i < n; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}
		
	long long result = 0;
	for (int i = 0; i < n; i++) {
		long long max_contrib = (menu[i] * pow2[i]) % MOD;
		long long min_contrib = (menu[i] * pow2[n - i - 1]) % MOD;

		result += (max_contrib - min_contrib + MOD) % MOD;
		result %= MOD;
	}

	cout << result;

	return 0;
}
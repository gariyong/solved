#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int n, l;
	cin >> n >> l;

	for (int i = l; i <= 100; i++) {
		long long temp = n - (long long)i * (i - 1) / 2;

		if (temp % i != 0) continue;
		if (temp < 0) continue;

		long long x = temp / i;

		for (int j = 0; j < i; j++) {
			cout << x + j << ' ';
		}

		return 0;
	}

	cout << -1 << '\n';

	return 0;
}
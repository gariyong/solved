#include <iostream>

using namespace std;

int check(int m, int n, int x, int y) {
	long long lcm = (m * n);

	for (int k = x; k <= lcm; k += m) {
		if ((k - 1) % n + 1 == y) {
			return k;
		}
	}
	return -1;
}

int main() {
	int t;

	cin >> t;

	while (t > 0) {
		int n, m, x, y;

		cin >> m >> n >> x >> y;

		cout << check(m, n, x, y) << '\n';

		t--;
	}

	return 0;
}
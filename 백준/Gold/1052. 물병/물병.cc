#include <iostream>

using namespace std;

int count_bottles(int n) {
	int cnt = 0;

	while (n > 0) {
		if (n % 2 == 1) cnt++;
		n /= 2;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int cnt = 0;
	while (true) {
		if (count_bottles(n) <= k) break;
		n++;
		cnt++;
	}

	cout << cnt;

	return 0;
}
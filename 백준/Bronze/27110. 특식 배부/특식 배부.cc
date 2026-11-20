#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;

		if (x <= n) {
			cnt += x;
		}
		else {
			cnt += n;
		}
	}

	cout << cnt;

	return 0;
}
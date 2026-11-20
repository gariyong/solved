#include <iostream>

using namespace std;

int main() {
	long long n, m, cnt_attack = 0;

	cin >> n >> m;

	if (n == 1) {
		cnt_attack += m - 1;
	}
	else if (m == 1) {
		cnt_attack += n - 1;
	}
	else {
		cnt_attack += (3 + 4 * (m - 2) + 2) * (n - 1) + (m - 1);
	}

	cout << cnt_attack;

	return 0;
}
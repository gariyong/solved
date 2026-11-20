#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, y;
	cin >> n >> x >> y;

	int xy = x * x + y * y;
	while (n--) {
		int a;
		cin >> a;

		cout << (a * a <= xy ? "YES" : "NO") << '\n';
	}

	return 0;
}
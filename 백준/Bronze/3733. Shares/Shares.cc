#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	while (cin >> x >> y) {
		cout << y / (x + 1) << '\n';
	}

	return 0;
}
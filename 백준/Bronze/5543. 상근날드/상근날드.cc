#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int h = 2001, d = 2001;

	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;

		h = min(x, h);
	}

	for (int i = 0; i < 2; i++) {
		int x;
		cin >> x;

		d = min(x, d);
	}

	cout << d + h - 50;

	return 0;
}
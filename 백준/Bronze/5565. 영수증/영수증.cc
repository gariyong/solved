#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < 9; i++) {
		int x;

		cin >> x;
		n -= x;
	}

	cout << n;

	return 0;
}
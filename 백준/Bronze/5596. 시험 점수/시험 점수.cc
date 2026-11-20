#include <iostream>

using namespace std;

int main() {
	int n[2] = { 0, };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			int x;

			cin >> x;
			n[i] += x;
		}
	}

	cout << (n[0] > n[1] ? n[0] : n[1]);

	return 0;
}
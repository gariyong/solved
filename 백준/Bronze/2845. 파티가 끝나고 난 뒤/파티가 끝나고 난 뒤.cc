#include <iostream>

using namespace std;

int main() {
	int l, p, sum;
	int place[5];

	cin >> l >> p;
	sum = l * p;

	for (int i = 0; i < 5; i++) {
		cin >> place[i];
		place[i] -= sum;

		cout << place[i] << ' ';
	}

	return 0;
}
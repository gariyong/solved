#include <iostream>

using namespace std;

int main() {
	long long p[101];
	int t;
	
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	p[4] = 2;
	p[5] = 2;
	p[6] = 3;
	p[7] = 4;
	p[8] = 5;
	p[9] = 7;
	p[10] = 9;

	for (int i = 11; i <= 100; i++) {
		p[i] = p[i - 2] + p[i - 3];
	}

	cin >> t;

	while (t > 0) {
		int n;

		cin >> n;
		cout << p[n] << '\n';
		t--;
	}

	return 0;
}
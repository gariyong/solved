#include <iostream>

using namespace std;

long long power(long long a, long long b, long long c) {
	long long result = 1;
	a %= c;

	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % c;
		}
		a = (a * a) % c;
		b /= 2;
	}

	return result;
}

int main() {
	long long A, B, C;

	cin >> A >> B >> C;

	cout << power(A, B, C);

	return 0;
}
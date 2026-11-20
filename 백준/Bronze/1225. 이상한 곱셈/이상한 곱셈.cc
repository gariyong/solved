#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int size_a = (int)a.size();
	int size_b = (int)b.size();
	if ((size_a == 1 && a[0] == '0') || size_b == 1 && b[0] == '0') {
		cout << 0 << '\n';
		
		return 0;
	}

	for (int i = 0; i < size_a; i++) {
		a[i] -= '0';
	}

	for (int j = 0; j < size_b; j++) {
		b[j] -= '0';
	}

	long long sum = 0;
	for (int i = 0; i < size_a; i++) {
		for (int j = 0; j < size_b; j++) {
			sum += a[i] * b[j];
		}
	}

	cout << sum << '\n';

	return 0;
}
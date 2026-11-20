#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b) {
	return a > b;
}

int main() {
	int n;
	int num[10];

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 10; i++) {
			cin >> num[i];
		}
		sort(num, num + 10, compare);
		cout << num[2] << '\n';
	}

	return 0;
}
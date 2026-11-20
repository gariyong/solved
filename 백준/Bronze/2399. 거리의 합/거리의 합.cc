#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int>num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			sum += (int)abs(num[i] - num[j]);
		}
	}

	cout << sum * 2;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> q(n);
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}

	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += q[i] - 1;
	}
	sum += q[n - 1];

	cout << sum;

	return 0;
}
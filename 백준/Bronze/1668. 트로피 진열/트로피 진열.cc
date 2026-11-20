#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	int highest = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > highest) {
			highest = arr[i];
			cnt++;
		}
	}

	cout << cnt << '\n';

	highest = -1;
	cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] > highest) {
			highest = arr[i];
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
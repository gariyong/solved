// 문제 : https://www.acmicpc.net/problem/1806
// 제목 : 부분합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int left = 0, right = 0;
	int len = n + 1, sum = 0;

	while (true) {
		if (sum >= s) {
			len = min(len, right - left);
			sum -= arr[left++];
		}
		else if (right == n) {
			break;
		}
		else {
			sum += arr[right++];
		}
	}

	cout << (len == n + 1 ? 0 : len) << '\n';

	return 0;
}

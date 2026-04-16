#include <iostream>
#include <vector>
#include <algorithm>

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
	sort(num.begin(), num.end());

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int cur = num[i];
		int left = 0;
		int right = n - 1;
		
		while (left < right) {
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}

			int sum = num[left] + num[right];
			if (sum == cur) {
				cnt++;
				break;
			}

			if (sum > cur) {
				right--;
			}
			else if (sum < cur) {
				left++;
			}
		}
	}

	cout << cnt;

	return 0;
}
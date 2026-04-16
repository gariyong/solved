#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& lis, int target) {
	int left = 0;
	int right = (int)lis.size();

	while (left < right) {
		int mid = (left + right) / 2;

		if (lis[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	vector<int>lis;
	vector<int>idx(n);
	for (int i = 0; i < n; i++) {
		int pos = binary_search(lis, num[i]);

		if (pos == (int)lis.size()) {
			lis.push_back(num[i]);
		}
		else {
			lis[pos] = num[i];
		}

		idx[i] = pos;
	}

	int len = (int)lis.size();
	cout << len << '\n';

	vector<int> result;
	for (int i = n - 1; i >= 0; i--) {
		if (idx[i] == len - 1) {
			result.push_back(num[i]);
			len--;
		}

		if (len == 0) break;
	}
	reverse(result.begin(), result.end());

	for (int x : result) {
		cout << x << ' ';
	}

	return 0;
}
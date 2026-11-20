#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bin_search(vector<int>& arr, vector<int>& ch, int n) {
	for (int i = 0; i < n; i++) {
		int high = (int) ch.size() - 1;
		int low = 0;
		int mid;

		while (low <= high) {
			mid = (high + low) / 2;

			if (arr[i] == ch[mid]) {
				cout << mid << '\n';
				break;
			}
			else if (arr[i] > ch[mid]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector <int> arr;
	vector <int> temp;
	vector <int> ch;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
		temp.push_back(x);
	}
	sort(temp.begin(), temp.end());

	ch.push_back(temp[0]);
	for (int i = 1; i < n; i++) {
		if (ch[(int) ch.size() - 1] != temp[i]) {
			ch.push_back(temp[i]);
		}
	}

	bin_search(arr, ch, n);

	return 0;
}
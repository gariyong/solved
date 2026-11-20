#include <iostream>

using namespace std;

void selection_sort(long long*& arr, int n, int k) {
	int cnt = 0;

	for (int i = n - 1; i >= 0; i--) {
		int max_j = i;

		for (int j = i - 1; j >= 0; j--) {
			if (arr[max_j] < arr[j]) {
				max_j = j;
			}
		}

		if (arr[max_j] != arr[i]) {
			long long tmp = arr[i];
			arr[i] = arr[max_j];
			arr[max_j] = tmp;
			cnt++;
		}
		if (cnt == k) {
			cout << arr[max_j] << ' ' << arr[i];
			break;
		}
	}

	if (cnt != k) {
		cout << -1;
	}
}

int main() {
	int n, k;
	long long* arr;

	cin >> n >> k;
	arr = new long long[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	selection_sort(arr, n, k);

	delete[] arr;

	return 0;
}
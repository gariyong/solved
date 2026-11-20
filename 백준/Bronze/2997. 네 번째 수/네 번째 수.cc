#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];

	sort(arr, arr + 3);
	int gap1 = arr[1] - arr[0];
	int gap2 = arr[2] - arr[1];

	if (gap1 == gap2) {
		cout << arr[2] + gap1;
	}
	else if (gap1 > gap2) {
		cout << arr[0] + gap2;
	}
	else {
		cout << arr[1] + gap1;
	}

	return 0;
}
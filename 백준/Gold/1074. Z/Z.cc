#include <iostream>
#include <cmath>

using namespace std;

int divid(int n, int r, int c) {
	int mid = n / 2;
	
	if (mid == 0) {
		return 0;
	}

	int size = mid * mid;
	if (r < mid && c >= mid) {
		return (size * 1) + divid(mid, r, c - mid);
	}
	else if (r < mid && c < mid) {
		return divid(mid, r, c);
	}
	else if (r >= mid && mid > c) {
		return (size * 2) + divid(mid, r - mid, c);
	}
	else if (r >= mid && c >= mid) {
		return (size * 3) + divid(mid, r - mid, c - mid);
	}
}

int main() {
	int n, r, c;
	int len;
	
	cin >> n >> r >> c;
	len = (int)pow(2, n);

	cout << divid(len, r, c);

	return 0;
}
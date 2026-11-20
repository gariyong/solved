#include <iostream>

using namespace std;

int main() {
	int n, w, h, l;
	cin >> n >> w >> h >> l;

	int w_cnt = w / l;
	int h_cnt = h / l;

	int result = w_cnt * h_cnt;
	if (result <= n) {
		cout << result;
	}
	else {
		cout << n;
	}

	return 0;
}
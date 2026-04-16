#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int prev_max[3] = { 0 };
	int prev_min[3] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++) {
		int cur_max[3] = { 0 };
		int cur_min[3] = { 0 };
		int a, b, c;

		cin >> a >> b >> c;

		cur_max[0] = (int)max(prev_max[0], prev_max[1]) + a;
		cur_max[1] = (int)max({ prev_max[0],prev_max[1], prev_max[2] }) + b;
		cur_max[2] = (int)max(prev_max[1], prev_max[2]) + c;

		cur_min[0] = (int)min(prev_min[0], prev_min[1]) + a;
		cur_min[1] = (int)min({ prev_min[0],prev_min[1], prev_min[2] }) + b;
		cur_min[2] = (int)min(prev_min[1], prev_min[2]) + c;

		for (int i = 0; i < 3; i++) {
			prev_max[i] = cur_max[i];
			prev_min[i] = cur_min[i];
		}
	}

	cout << max({ prev_max[0], prev_max[1], prev_max[2] }) << ' ' << min({ prev_min[0], prev_min[1], prev_min[2] });

	return 0;
}
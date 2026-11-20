#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b) {
	return a > b;
}

int main() {
	int t;
	
	cin >> t;
	while (t--) {
		int n, m;
		int cnt = 0;
		int* imp;
		queue <pair<int, int>> printer;

		cin >> n >> m;
		imp = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> imp[i];
			printer.push({ imp[i], i });
		}
		sort(imp, imp + n, compare);

		while (true) {
			if (printer.front().first == imp[cnt]) {
				if (printer.front().second == m) {
					cnt++;
					break;
				}
				else {
					printer.pop();
					cnt++;
				}
			}
			else {
				int cmp[2] = { printer.front().first, printer.front().second };
				printer.pop();
				printer.push({ cmp[0], cmp[1] });
			}
		}
		cout << cnt << '\n';

		delete[] imp;
	}

	return 0;
}
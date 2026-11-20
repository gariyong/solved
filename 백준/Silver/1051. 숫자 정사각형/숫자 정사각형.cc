#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> square(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			square[i][j] = s[j] - '0';
		}
	}

	int result = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int d = 1; i + d < n && j + d < m; d++) {
				if (square[i][j] == square[i][j + d]) {
					int cur = square[i][j];

					if (square[i][j + d] == cur && square[i + d][j] == cur && square[i + d][j + d] == cur) {
						result = max(result, (d + 1) * (d + 1));
					}
				}
			}
		}
	}

	cout << result;

	return 0;
}
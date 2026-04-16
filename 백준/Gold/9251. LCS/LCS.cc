#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string a, b;
	int n, m;

	cin >> a >> b;

	n = (int)a.size();
	m = (int)b.size();

	vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	cout << lcs[n][m];

	return 0;
}
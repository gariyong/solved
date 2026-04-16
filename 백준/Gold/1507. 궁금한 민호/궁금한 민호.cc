#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> dist(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool is_need = true;

			for (int k = 0; k < n; k++) {
				if (k == i || k == j) continue;

				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					cout << -1;
					
					return 0;
				}

				if (dist[i][j] == dist[i][k] + dist[k][j]) {
					is_need = false;
					break;
				}
			}
			if (is_need) result += dist[i][j];
		}
	}

	cout << result;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& str, int start, int target) {
		for (int i = start; i < str.size(); i++) {
		if (str[i] == target) {
			return i;
		}
	}

		return -1;
}

int main() {
	int n, m;

	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	cin >> m;
	vector<int> b(m);

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int i = 0, j = 0;
	vector<int> result;

	while (i < n && j < m) {
		int max_element = -1;

		for (int num = 100; num >= 1; num--) {
			int next_a = find(a, i, num);
			int next_b = find(b, j, num);

			if(next_a != -1 && next_b != -1) {
				max_element = num;
				i = next_a + 1;
				j = next_b + 1;
				result.push_back(max_element);

				break;
			}
		}

		if(max_element == -1) {
			break;
		}
	}

	cout << result.size() << endl;
	if (!result.empty()) {
		for (int k = 0; k < result.size(); k++) {
			cout << result[k] << " ";
		}
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Guitar_str{
	int individual;
	int package;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Guitar_str>strings(m);
	for (int i = 0; i < m; i++) {
		cin >> strings[i].package >> strings[i].individual;
	}

	int min_6str = 1e9;
	int min_1str = 1e9;
	for (auto& cur : strings) {
		min_6str = min(min_6str, min(cur.individual * 6, cur.package));
		min_1str = min(min_1str, cur.individual);
	}
	
	int result;
	if (n % 6 != 0) {
		result = min(min_6str * (n / 6 + 1), min_6str * (n / 6) + min_1str * (n % 6));
	}
	else {
		result = min(min_6str * (n / 6), min_1str * n);
	}

	cout << result;

	return 0;
}
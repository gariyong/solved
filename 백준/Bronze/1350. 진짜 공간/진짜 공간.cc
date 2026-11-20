#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> files(n);
	for (int i = 0; i < n; i++) {
		cin >> files[i];
	}

	int cluster_size;
	cin >> cluster_size;

	long long disk_space = 0;
	for (int i = 0; i < n; i++) {
		if (files[i] % cluster_size == 0) {
			disk_space += (long long)cluster_size * (files[i] / cluster_size);
		}
		else {
			disk_space += (long long)cluster_size * (files[i] / cluster_size + 1);
		}
	}

	cout << disk_space;

	return 0;
}
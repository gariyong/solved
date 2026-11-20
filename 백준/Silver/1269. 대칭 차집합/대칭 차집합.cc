#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	map<int, bool> seq_a;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		seq_a[a[i]] = true;
	}

	vector<int> b(m);
	map<int, bool> seq_b;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		seq_b[b[i]] = true;
	}
	
	for (int x : a) {
		if (seq_b.find(x) != seq_b.end()) {
			seq_b.erase(x);
		}
	}

	for (int x : b) {
		if (seq_a.find(x) != seq_a.end()) {
			seq_a.erase(x);
		}
	}

	seq_a.merge(seq_b);
	cout << seq_a.size();

	return 0;
}
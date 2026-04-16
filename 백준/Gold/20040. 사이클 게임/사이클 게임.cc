#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int>& parent) {
	if(parent[x] == x) return x;

	return parent[x] = find(parent[x], parent);
}

bool unite(int a, int b, vector<int>& parent) {
	a = find(a, parent);
	b = find(b, parent);

	if (a == b) return true;
	parent[b] = a;         

	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> parent(n);
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int turn = 0;
	while (turn < m) {
		turn++;
		int a, b;
		cin >> a >> b;

		if(unite(a, b, parent)) {
			cout << turn;

			return 0;
		}
	}
	cout << 0;

	return 0;
}
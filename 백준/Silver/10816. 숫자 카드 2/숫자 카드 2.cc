#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int* v;
	cin >> n;
	v = new int[n];

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v[i] = num;
	}
	sort(v, v+n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int card;
		cin >> card;
		cout << upper_bound(v, v+n, card) - lower_bound(v, v+n, card) << " ";
	}

	delete[] v;

	return 0;
}
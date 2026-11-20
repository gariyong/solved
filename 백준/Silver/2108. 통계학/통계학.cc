#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

using namespace std;

int main() {
	int n, m, mode = -1, mode_n;
	int mode_count = 0;
	double sum = 0, avg;
	vector<int> v;
	vector<int> vc(8001, 0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
		vc[4000+m]++;
		sum += (double)m;
	}

	avg = round(sum / n);
	if (avg == -0) {
		avg = 0;
	}

	cout << avg << '\n';
	
	sort(v.begin(), v.end());
	cout << v[n / 2] << '\n';
	
	for (int i = 0; i < 8001; i++) {
		if (vc[i] > mode) {
			mode = vc[i];
			mode_n = i - 4000;
		}
	}

	for (int i = 0; i < 8001; i++) {
		if (vc[i] == mode) {
			mode_count++;
			if (mode_count == 2) {
				mode_n = i - 4000;
				break;
			}
		}
	}
	cout << mode_n << '\n';

	cout << v.back() - v.front();

	return 0;
}
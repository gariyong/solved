// 문제 : https://www.acmicpc.net/problem/7453
// 제목 : 합이 0인 네 정수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	vector<long long> ab, cd;
	ab.reserve((long long)n * n);
	cd.reserve((long long)n * n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(cd.begin(), cd.end());

	long long cnt = 0;
	for (long long x : ab) {
		auto len = equal_range(cd.begin(), cd.end(), -x);
		cnt += len.second - len.first;
	}

	cout << cnt;

	return 0;
}
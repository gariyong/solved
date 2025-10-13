// 문제 : https://www.acmicpc.net/problem/2143
// Á¦¸ñ : 두 배열의 합

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	int n;
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m;
	cin >> m;

	vector<long long> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	map<long long, int> sub_b;
	for (int i = 0; i < m; i++) {
		long long sum = 0;

		for (int j = i; j < m; j++) {
			sum += b[j];
			sub_b[sum]++;
		}
	}

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		long long sum = 0;

		for (int j = i; j < n; j++) {
			sum += a[j];

			if (sub_b.count(t - sum)) {
				cnt += sub_b[t - sum];
			}
		}
	}

	cout << cnt;

	return 0;
}

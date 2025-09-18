// 巩力 : https://www.acmicpc.net/problem/2473
// 力格 : 技 侩咀

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> sol(n);
	for (int i = 0; i < n; i++) {
		cin >> sol[i];
	}
	sort(sol.begin(), sol.end());

	tuple<int, int, int> res_sol;
	long long sum = INF;

	for (int i = 0; i < n; i++) {
		int left = i + 1;
		int right = n - 1;

		while (left < right) {
			long long cur_sum = sol[i] + sol[left] + sol[right];

			if (abs(sum) > abs(cur_sum)) {
				sum = cur_sum;
				res_sol = make_tuple(sol[i], sol[left], sol[right]);
			}

			if (cur_sum > 0) {
				right--;
			}
			else if (cur_sum < 0) {
				left++;
			}
			else {
				cout << get<0>(res_sol) << " " << get<1>(res_sol) << " " << get<2>(res_sol);

				return 0;
			}
		}
	}

	cout << get<0>(res_sol) << " " << get<1>(res_sol) << " " << get<2>(res_sol);

	return 0;
}
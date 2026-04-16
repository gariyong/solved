#include <iostream>
#include <map>

using namespace std;

map<long long, long long> dp;
long long p, q;

long long calculate(long long x) {
	if (x == 0) return 1;
	if (dp.count(x)) return dp[x];

	return dp[x] = calculate(x / p) + calculate(x / q);
}

int main() {
	long long n;
	cin >> n >> p >> q;

	cout << calculate(n);

	return 0;
}
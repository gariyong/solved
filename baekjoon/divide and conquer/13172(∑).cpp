// 문제: https://www.acmicpc.net/problem/13172
// 제목: ∑

#include <iostream>

using namespace std;

// 처음엔 브루트포스로 접근했지만, 시간초과가 발생 이후 분할 정복을 이용한 접근으로 변경
long long mod_mult(long long a, long long b) {
	long long result = 1;
	a %= 1000000007;

	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % 1000000007;
		}
		a = (a * a) % 1000000007;
		b /= 2;
	}

	return result;
}

int main() {
	int n;
	long long result = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long a, b;
		long long e;

		cin >> a >> b;
		e = mod_mult(a, 1000000005);
		result = (result + (b * e) % 1000000007) % 1000000007;
	}

	cout << result;

	return 0;
}

// 11444�� �Ǻ���ġ �� 6
// https://www.acmicpc.net/problem/11444
// ��ȭ���� �����̰�, n�� �ſ� Ŭ ���� ��� �ŵ������� ����Ͽ� ���
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

vector<vector<ll>> matrix_mult(vector<vector<ll>>& a, vector<vector<ll>>& b) {
	vector<vector<ll>> result(2, vector<ll>(2, 0));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	return result;
}

vector<vector<ll>> matrix_pow(vector<vector<ll>>& base, ll exp) {
	vector<vector<ll>> result = { {1, 0}, {0, 1} };

	while (exp > 0) {
		if (exp % 2 == 1) {
			result = matrix_mult(result, base);
		}
		base = matrix_mult(base, base);
		exp /= 2;
	}

	return result;
}

int main() {
	ll n;

	cin >> n;

	if (n == 0) {
		cout << 1;

		return 0;
	}

	vector<vector<ll>> base = { {1, 1}, {1, 0} };
	vector<vector<ll>> result = matrix_pow(base, n - 1);

	cout << result[0][0];

	return 0;
}
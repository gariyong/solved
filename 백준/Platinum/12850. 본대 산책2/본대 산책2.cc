#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;
const long long MOD = 1000000007;

matrix a = {
	{0,1,1,0,0,0,0,0} ,
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,1,0},
	{0,0,0,1,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0}
};

matrix multi(matrix& A, matrix& B) {
	matrix result(8, vector<long long>(8, 0));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
			}
		}
	}

	return result;
}

void pow(int d) {
	matrix result(8, vector<long long>(8, 0));
	for (int i = 0; i < 8; i++) {
		result[i][i] = 1;
	}

	matrix base = a;

	while (d > 0) {
		if (d % 2 == 1) {
			result = multi(result, base);
		}
		
		base = multi(base, base);
		d /= 2;
	}

	cout << result[0][0] % MOD;
}

int main() {
	int d;
	cin >> d;

	pow(d);

	return 0;
}
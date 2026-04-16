#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix multiMatrix(Matrix& matrix_1, Matrix& matrix_2, int n) {
	Matrix newmatrix(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				newmatrix[i][j] += (matrix_1[i][k] * matrix_2[k][j]) % 1000;
				newmatrix[i][j] %= 1000;
			}
		}
	}

	return newmatrix;
}

Matrix dividMatrix(Matrix& matrix, long long B, int n) {
	if (B == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] %= 1000;
			}
		}

		return matrix;
	}

	Matrix half = dividMatrix(matrix, B / 2, n);
	Matrix result = multiMatrix(half, half, n);

	if (B % 2 == 1) {
		result = multiMatrix(result, matrix, n);
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long B;
	Matrix matrix, result;

	cin >> n >> B;
	matrix.resize(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	result = dividMatrix(matrix, B, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
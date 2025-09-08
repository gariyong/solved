// ���� : https://www.acmicpc.net/problem/9252
// ���� : LCS 2
// backtracking + dp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int backtracking(vector<vector<int>>& dp, string& A, string& B, int i, int j) {
	if (i == A.size() || j == B.size()) {
		return 0;
	}

	// �����Լ��� �ƴ� ����Լ����� dp�迭�� ������ ���� ���� �������� �����ϴ°� ����
	int& len = dp[i][j]; // ���� �������� �����ؼ� dp�迭�� ���� �����ϴ°� �ƴ� ���� �����ؼ� ������
	if (len != -1) {
		return len;
	}

	if (A[i] == B[j]) {
		len = 1 + backtracking(dp, A, B, i + 1, j + 1);
	}
	else {
		len = max(backtracking(dp, A, B, i + 1, j), backtracking(dp, A, B, i, j + 1));
	}

	return len;
}

string reconstruct(vector<vector<int>>& dp, string& A, string& B, int i, int j) {
	if (i == A.size() || j == B.size()) {
		return "";
	}

	if (A[i] == B[j]) {
		return A[i] + reconstruct(dp, A, B, i + 1, j + 1);
	}
	else {
		if (dp[i][j] == dp[i + 1][j]) {
			return reconstruct(dp, A, B, i + 1, j);
		}
		else {
			return reconstruct(dp, A, B, i, j + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;

	vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
	int len = backtracking(dp, A, B, 0, 0);
	string lcs = reconstruct(dp, A, B, 0, 0);

	if (len == 0) {
		cout << 0 << "\n";
	}
	else {
		cout << len << "\n" << lcs << "\n";
	}

	return 0;
}
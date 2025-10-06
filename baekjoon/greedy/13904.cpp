// ���� : https://www.acmicpc.net/problem/13904
// ���� : ����

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

// ���� ����ü : ������(d)�� ����(w) ����
struct Assignment {
	int d;
	int w;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // ������ ��
	cin >> n;

	vector<Assignment> assignments(n);
	for (int i = 0; i < n; i++) {
		cin >> assignments[i].d >> assignments[i].w; // �� ������ �����ϰ� ������ �Է�
	}

	// ������ ���� �������� ����, ���� ���� �������� ����
	sort(assignments.begin(), assignments.end(), [](const Assignment& a, const Assignment& b) {
		if (a.d != b.d) {
			return a.d < b.d; // �������� ���� ����
		}

		return a.w > b.w; // ������ ���� ����
		});

	// �켱���� ť: �ּ� ��, ���� ������ ������ �� ������ ���� ���� ���� top���� �÷�����
	priority_queue<int, vector<int>, greater<int>> q;

	for (auto& hw : assignments) {
		int d = hw.d; // ���� ������
		int w = hw.w; // ���� ����

		int cnt = (int)q.size(); // ���� ���õ� ���� �� == ��¥

		// ���� ���õ� ���� ���� ������ ���� ������ ����
		if (cnt < d) {
			q.push(w);
		}

		// ���õ� ���� ���� �����ϰ� ������ �� ���� ������ ������ ��ü ����
		else if (cnt == d) {
			if (!q.empty() && w > q.top()) {
				q.pop();
				q.push(w);
			}
		}
	}

	// ���õ� �������� ������ �� ���
	int score = 0;
	while (!q.empty()) {
		int x = q.top();
		q.pop();

		score += x;
	}

	// �ִ� ���� ���
	cout << score;

	return 0;
}
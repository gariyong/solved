// ���� : https://www.acmicpc.net/problem/2162
// ���� : ���� �׷�
// �˰��� : CCW(Count ClockWise)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ���� ����ü : �� �� (a, b)�� ������
struct Line_seg {
	pair<int, int> a, b;
};

// �θ� ��带 ã�� �Լ�
int find(vector<int>& parent, int x) {
	if (parent[x] == x) {
		return parent[x];
	}

	return parent[x] = find(parent, parent[x]);
}

// �� ������ ��ġ�� �Լ�
// cnt[x] : �ش� �׷��� ���� ����
void unite(vector<int>& parent, vector<int>& cnt, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);

	if (a != b) {
		// b �׷쿡 a �׷��� ��ħ
		parent[a] = b;
		cnt[b] += cnt[a]; // �׷� ũ�� ��ġ��
		cnt[a] = 0;		  // ����� �׷��� ũ��� 0
	}
}

// CCW (Counter ClockWise) �˰���
// res > 0 : �ݽð� ����
// res < 0 : �ð� ����
// res = 0 : ������
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	int res = (p2.first - p1.first) * (p3.second - p1.second)
		- (p2.second - p1.second) * (p3.first - p1.first);

	if (res > 0) {
		return 1;
	}
	else if (res < 0) {
		return -1;
	}

	return 0;
}

// CCW ���� �̿��Ͽ� ���� ������ �����ϴ� �Լ�
// 1. �Ϲ� ���� : ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0
// 2. ������ ���� ��쿣 ��ǥ �񱳷� ��ħ ����
bool is_cross(Line_seg l, Line_seg r) {
	int ccw1 = ccw(l.a, l.b, r.a);
	int ccw2 = ccw(l.a, l.b, r.b);
	int ccw3 = ccw(r.a, r.b, l.a);
	int ccw4 = ccw(r.a, r.b, l.b);

	// �� ������ �����ϰų� ��� ���
	if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
		// �� �� ��� ������ �� �ִ� ���
		if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
			// �� ������ �� ���� ����
			if (l.a > l.b) swap(l.a, l.b);
			if (r.a > r.b) swap(r.a, r.b);

			// ��ġ�� �ʴ� ��� ����
			return !(l.b < r.a || r.b < l.a);
		}

		// ����
		return true;
	}

	// �������� ����
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Line_seg>lines(n);
	for (int i = 0; i < n; i++) {
		cin >> lines[i].a.first >> lines[i].a.second >> lines[i].b.first >> lines[i].b.second;
	}

	// �� ������ ������ �������� �ʱ�ȭ
	vector<int>parent(n);
	vector<int>cnt(n, 1); // �ʱ� �׷� ũ�� = 1
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	// ��� ���� ���� ���Ͽ� �����ϸ� ���� �׷����� ��ħ
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (is_cross(lines[i], lines[j])) {
				unite(parent, cnt, i, j);
			}
		}
	}


	int groups = 0;
	int max_size = 0;
	for (int i = 0; i < n; i++) {
		int cur = find(parent, i); // ��ǥ ��� ã��

		if (cur == i) { // ��Ʈ ���� ���ο� �׷�
			groups++;
		}

		max_size = max(max_size, cnt[cur]); // �ִ� �׷� ũ�� ����
	}

	cout << groups << '\n' << max_size; // ��� ���

	return 0;
}
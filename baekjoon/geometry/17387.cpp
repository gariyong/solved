// ���� : https://www.acmicpc.net/problem/17387
// ���� : ���� ���� 2
// �˰��� : CCW(Counter ClockWise) �˰���

#include <iostream>
#include <algorithm>

using namespace std;

// ������ ǥ���ϱ� ���� ����ü
// a, b �� ������ �� ���� (pair< x, y >)
struct Line_seg {
	pair<long long, long long> a, b;
};


// CCW �Լ�
// �� �� p1, p2, p3 �� ���� �Ʒ� ���� ����Ѵ�:
// res = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)
// �� ���� 2���� ������ ����(cross product)�� �ش��Ѵ�.
// �ؼ�:
// res > 0 -> p1 -> p2 -> p3 �� �ݽð� ���� (CCW)
// res < 0 -> p1 -> p2 -> p3 �� �ð� ���� (CW)
// res == 0 -> �� ���� �� ����(line)�� ���� ���� (collinear)
// ������ ��ȣ�� ���� (p1->p2) �� �������� p3 �� ����(���)���� ������(����)������ �˷��ش�.
// 2���������� ������ ����(��ȣ)�� ����(����)�� ���� ������ �ش�.

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
	long long res = (p2.first - p1.first) * (p3.second - p1.second)
		- (p2.second - p1.second) * (p3.first - p1.first);


	if (res > 0) {
		return 1; // �ݽð�
	}
	else if (res < 0) {
		return -1; // �ð�
	}


	return 0; // ������
}

// �� ���� l, r �� �����ϴ��� �����ϴ� �Լ�
// ���̵�� ���:
// 1) �Ϲ����� ���: �� ���� AB, CD �� �����Ϸ���
// ccw(A,B,C) * ccw(A,B,D) <= 0 && ccw(C,D,A) * ccw(C,D,B) <= 0
// �� �����ؾ� �Ѵ�.
// (���� C�� D�� AB�� ���ʿ� �ְ�, A�� B�� CD�� ���ʿ� �ִ��� �˻�)
// 2) Ư���� ���: �� �� ��� �� ���� ���� �ִ� ���(��� ccw == 0)
// �̶��� �� ������ ����(��ǥ ����)�� ���ؼ� ������ ��ġ���� Ȯ���ؾ� �Ѵ�.
// (��: [----A----B----] �� [----C----D----] �� ��ġ���� Ȯ��)
// ���� ���λ���:
// - pair �� �� ������(>, <)�� ���� first(x)�� ���ϰ� ������ second(y)�� ���Ѵ�.
// - �������� ���� �� ������ ������ ������������ ������ �� ������ ��ġ���� �˻��Ѵ�.
// - ������ (x, y) ������ ���ĵǹǷ� ����/���� �� ��� ��쿡 �����ϵ��� ����ȴ�.

bool is_cross(Line_seg l, Line_seg r) {
	int ccw1 = ccw(l.a, l.b, r.a);
	int ccw2 = ccw(l.a, l.b, r.b);
	int ccw3 = ccw(r.a, r.b, l.a);
	int ccw4 = ccw(r.a, r.b, l.b);


	// �� ������ ������ �� �ִ� �⺻ ����
	if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
		// �� ���� ��� �������� �ִ� Ư�� ���̽�
		if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
			// �� ������ ������ ���� ������ �����Ѵ�.
			// pair �� ���ؼ��� �⺻ �񱳿����ڰ� ���ǵǾ� �־ (x, y) �������� ���ĵȴ�.
			if (l.a > l.b) swap(l.a, l.b);
			if (r.a > r.b) swap(r.a, r.b);


			// �� ������ ��ġ���� Ȯ��
			// ��ġ�� �ʴ� ������ (l.b < r.a) �Ǵ� (r.b < l.a)
			// ���� ��ġ�� !(l.b < r.a || r.b < l.a)
			return !(l.b < r.a || r.b < l.a);
		}
		// �������� �ƴ� ����� ���� ���Ǹ����ε� ������ ����
		return true;
	}


	// �⺻ ���� �Ҹ��� -> �������� ����
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	Line_seg l, r;
	// �Է�: ù �� AB (x1 y1 x2 y2), ��° �� CD (x3 y3 x4 y4)
	cin >> l.a.first >> l.a.second >> l.b.first >> l.b.second;
	cin >> r.a.first >> r.a.second >> r.b.first >> r.b.second;


	cout << is_cross(l, r);


	return 0;
}
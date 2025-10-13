// 문제 : https://www.acmicpc.net/problem/20040
// 제목 : 사이클 게임

#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int>& parent) {
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x], parent);
}

bool unite(int a, int b, vector<int>& parent) {
	a = find(a, parent);
	b = find(b, parent);

	if (a == b) return true;
	parent[b] = a;

	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> parent(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	// 처음에 출력할 때 ((trun == m) ? 0 : turn) 이렇게 했더니 사이클이 생기는 턴이 m일 때 trun을 출력하지 못했음
	// 그래서 turn을 사이클이 생기는 시점에 출력하도록 수정
	int turn = 0;
	while (turn < m) {
		turn++;
		int a, b;
		cin >> a >> b;

		if (unite(a, b, parent)) {
			cout << turn;

			return 0;
		}
	}
	cout << 0;

	return 0;
}

// 문제 : https://www.acmicpc.net/problem/10775
// 제목 : 공항
// 알고리즘 : union-find

#include <iostream>
#include <vector>

using namespace std;


// find 함수 : 주어진 게이트 x가 속한 루트(즉, 현재 도킹 가능한 가장 큰 게이트 번호)를 찾는다.
// 경로 압축(Path Compression)을 이용해 효율적으로 부모를 갱신한다.
int find(vector<int>& parent, int x) {
	if (parent[x] == x) {
		return x; // 자기 자신이 루트라면 그대로 반환
	}
	return parent[x] = find(parent, parent[x]); // 루트를 찾아가면서 부모를 갱신
}

// unite 함수 : 두 집합(게이트)을 합친다.
// a 게이트를 b 게이트와 연결 → 즉, a 게이트는 이제 사용할 수 없고, 다음엔 b 게이트로 연결됨을 의미
void unite(vector<int>& parent, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);
	parent[a] = b; // a의 루트를 b로 연결
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int g, p;
	cin >> g >> p; // g: 게이트 수, p: 비행기 수

	// parent 배열 초기화: i번 게이트의 부모를 자기 자신으로 설정
	vector<int> gate(g + 1);
	for (int i = 0; i <= g; i++) {
		gate[i] = i;
	}

	int cnt = 0; // 도킹 성공한 비행기 수
	for (int i = 0; i < p; i++) {
		int g_i;
		cin >> g_i; // 각 비행기가 도킹하려는 최대 게이트 번호

		// 현재 비행기가 도킹 가능한 가장 큰 게이트 번호를 찾음
		int docking_gate = find(gate, g_i);

		// docking_gate == 0 이면 더 이상 도킹할 수 있는 게이트가 없음
		if (docking_gate == 0) break;

		// docking_gate 게이트에 도킹 완료
		// 이제 이 게이트는 사용 불가능하므로, 다음엔 docking_gate - 1로 연결
		unite(gate, docking_gate, docking_gate - 1);

		cnt++; // 도킹 성공
	}

	cout << cnt; // 도킹 가능한 최대 비행기 수 출력

	return 0;
}

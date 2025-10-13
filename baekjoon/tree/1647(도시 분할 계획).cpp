// 문제 : https://www.acmicpc.net/problem/1647
// 제목 : 도시 분할 계획

// 다익스트라로 접근했으나 시작 정점을 어디로 잡느냐에 따라 답이 달라지는 문제가 발생
// 크루스칼 or 프림 알고리즘 중 크루스칼로 풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Edge {
    int a, b, cost;
} Edge;

int find(int x, vector<int>& parent) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);

    if (a != b) {
        if (a < b) {
            parent[b] = a;
        }
        else {
            parent[a] = b;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int cost = 0;
    int max_cost = 0;

    cin >> n >> m;
    vector<int> parent(n + 1);
    vector<Edge> edges(m);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
    }

    //  람다 함수 정렬
    // 한 번 쓰고 버릴 함수 => 람다(익명) 함수로 전달 가능
    sort(edges.begin(), edges.end(), [](Edge& e1, Edge& e2) {
        return e1.cost < e2.cost;
        });

    for (int i = 0; i < m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int c = edges[i].cost;

        if (find(a, parent) != find(b, parent)) {
            unite(a, b, parent);
            cost += c;
            max_cost = max(max_cost, c);
        }
    }

    cout << cost - max_cost;

    return 0;
}

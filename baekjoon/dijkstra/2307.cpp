// 문제 : https://www.acmicpc.net/problem/2307
// 제목 : 도로검문
// 알고리즘 : 다익스트라 + 역추적

#include<iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

// 다익스트라 알고리즘 (도로 하나를 막을 수 있도록 block_u, block_v 인자 추가)
pair<vector<int>, vector<int>> dijkstra(
    vector<vector<pair<int, int>>>& nodes, // 그래프 (인접 리스트)
    int n,                                 // 노드 개수
    int start,                             // 시작 노드
    int block_u = -1,                      // 막을 간선의 한쪽 끝
    int block_v = -1                       // 막을 간선의 다른 쪽 끝
) {
    vector<int> dist(n + 1, INF);     // 최단거리 배열
    vector<int> parent(n + 1, -1);    // 경로 복원을 위한 부모 배열
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // 최소 힙 (비용, 노드)

    // 시작 노드 초기화
    q.push({ 0, start });
    dist[start] = 0;

    while (!q.empty()) {
        auto [cost, cur] = q.top(); // 현재까지의 거리, 현재 노드
        q.pop();

        if (cost > dist[cur]) continue; // 이미 더 짧은 경로가 있으면 스킵

        // 현재 노드와 연결된 모든 간선을 탐색
        for (auto [w, next] : nodes[cur]) {
            // 현재 간선이 "막힌 도로"라면 무시
            if ((cur == block_u && next == block_v) || (cur == block_v && next == block_u)) continue;

            // 더 짧은 경로를 찾은 경우 갱신
            if (dist[next] > cost + w) {
                dist[next] = cost + w;
                parent[next] = cur;
                q.push({ dist[next], next });
            }
        }
    }

    return { dist, parent }; // (최단거리, 부모배열) 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 그래프 입력
    // nodes[u] = { (가중치, 목적지) } 형식
    vector<vector<pair<int, int>>> nodes(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        nodes[u].push_back({ w, v });
        nodes[v].push_back({ w, u }); // 양방향 도로
    }

    // 1번 → N번의 기본 최단경로 구하기
    auto [dist, parent] = dijkstra(nodes, n, 1);

    // 도달 불가능하면 바로 -1 출력
    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }

    int origin = dist[n]; // 원래 최단거리 저장

    // 최단경로에 포함된 간선 추출 (parent 배열 이용)
    vector<pair<int, int>> path;
    int cur = n;
    while (parent[cur] != -1) {
        path.push_back({ cur, parent[cur] }); // (현재노드, 부모노드)
        cur = parent[cur];
    }

    int result = 0; // 최대 지연 시간
    bool flag = false; // 도달 불가능한 경우 감지용

    // 최단경로의 각 간선을 하나씩 막으면서 재탐색
    for (auto [u, v] : path) {
        auto [dist2, _] = dijkstra(nodes, n, 1, u, v); // 간선 (u, v) 막기

        if (dist2[n] == INF) {
            // 도로 하나 막으면 N에 도달 불가 → 바로 -1 출력 예정
            flag = true;
            break;
        }

        // 기존보다 얼마나 더 늦어지는지 계산
        result = max(result, dist2[n] - origin);
    }

    if (flag) {
        cout << -1;
    }
    else {
        cout << result;
    }

    return 0;
}
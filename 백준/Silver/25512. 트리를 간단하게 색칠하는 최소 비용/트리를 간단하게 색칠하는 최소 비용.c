#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

// 새로운 인접 리스트 노드를 생성하는 함수
Node* create_node(int vertex) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

// 인접 리스트에 엣지를 추가하는 함수
void add_edge(AdjList* adj_list, int src, int dest) {
    Node* new_node = create_node(dest);
    new_node->next = adj_list[src].head;
    adj_list[src].head = new_node;

    // 무방향 그래드이므로 dest에서 src로의 엣지도 추가합니다.
    new_node = create_node(src);
    new_node->next = adj_list[dest].head;
    adj_list[dest].head = new_node;
}

// DFS 탐색을 통해 비용을 계산하는 함수
void dfs(int n, int v, long long** w_b, long long* cost, int* visit, AdjList* adj_list) {
    visit[v] = 1;

    if (w_b[v][2] == 0) {
        cost[0] += w_b[v][0];
    }
    else if (w_b[v][2] == 1) {
        cost[0] += w_b[v][1];
    }

    Node* temp = adj_list[v].head;
    while (temp != NULL) {
        int u = temp->vertex;
        if (visit[u] == 0) {
            if (w_b[v][2] == 0) {
                w_b[u][2] = 1;
            }
            else if (w_b[v][2] == 1) {
                w_b[u][2] = 0;
            }
            dfs(n, u, w_b, cost, visit, adj_list);
        }
        temp = temp->next;
    }
}

int main() {
    int n;
    long long* cost;
    int* visit;
    AdjList* adj_list;
    long long** w_b;

    scanf("%d", &n);

    // 인접 리스트 초기화
    adj_list = (AdjList*)malloc(n * sizeof(AdjList));
    for (int i = 0; i < n; i++) {
        adj_list[i].head = NULL;
    }

    // 엣지 입력받기
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(adj_list, a, b);
    }

    // 색칠 비용 입력받기
    w_b = (long long**)malloc(sizeof(long long*) * n);
    for (int i = 0; i < n; i++) {
        w_b[i] = (long long*)malloc(sizeof(long long) * 3);
        scanf("%lld %lld", &w_b[i][0], &w_b[i][1]);
    }

    // 비용과 방문 배열 초기화
    cost = (long long*)calloc(2, sizeof(long long));
    visit = (int*)calloc(n, sizeof(int));

    // 루트 노드를 색상 0으로 색칠하고 DFS 수행
    w_b[0][2] = 0;
    dfs(n, 0, w_b, cost, visit, adj_list);

    long long cost1 = cost[0];
    cost[0] = 0;

    // 방문 배열 리셋 후 루트 노드를 색상 1로 색칠하고 DFS 수행
    memset(visit, 0, sizeof(int) * n);
    w_b[0][2] = 1;
    dfs(n, 0, w_b, cost, visit, adj_list);

    long long cost2 = cost[0];

    // 최소 비용 출력
    if (cost1 < cost2) {
        printf("%lld\n", cost1);
    }
    else {
        printf("%lld\n", cost2);
    }

    // 할당된 메모리 해제
    for (int i = 0; i < n; i++) {
        Node* temp = adj_list[i].head;
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(adj_list);

    for (int i = 0; i < n; i++) {
        free(w_b[i]);
    }
    free(w_b);
    free(cost);
    free(visit);

    return 0;
}

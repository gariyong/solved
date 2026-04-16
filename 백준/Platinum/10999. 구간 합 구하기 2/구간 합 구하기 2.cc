#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 1000000;
ll tree[MAX * 4 + 1];
ll lazy[MAX * 4 + 1];
ll num[MAX + 1];

ll init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];

	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update_lazy(int start, int end, int node) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        
        lazy[node] = 0;
    }
}

void update_range(int start, int end, int left, int right, int node, ll val) {
    update_lazy(start, end, node);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        tree[node] += (end - start + 1) * val;
        
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        
        return;
    }
    
    int mid = (start + end) / 2;
    update_range(start, mid, left, right, node * 2, val);
    update_range(mid + 1, end, left, right, node * 2 + 1, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int start, int end, int left, int right, int node) {
    update_lazy(start, end, node);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) cin >> num[i];
	init(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			int b, c;
			ll d;
			cin >> b >> c >> d;

			update_range(1, n, b, c, 1, d);
		}
		else if (a == 2) {
			int b, c;
			cin >> b >> c;

			cout << query(1, n, b, c, 1) << '\n';
		}
	}

	return 0;
}
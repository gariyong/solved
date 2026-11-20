#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>

int main() {
    int n;
    scanf("%d", &n);

    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int, int>> > q;

    while (n--) {
        int x;
        scanf("%d", &x);

        if (x == 0) {
            if (!q.empty()) {
                printf("%d\n", q.top().second);
                q.pop();
            } else {
                printf("0\n");
            }
        } else {
            q.push({ std::abs(x), x });
        }
    }

    return 0;
}
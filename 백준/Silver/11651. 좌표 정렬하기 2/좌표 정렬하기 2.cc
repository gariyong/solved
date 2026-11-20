#include <iostream>
#include <algorithm>
#include <vector>

struct Coordinate {
    int x;
    int y;
};

bool compare(Coordinate a, Coordinate b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main() {
    int n;

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    std::vector<Coordinate> points(n);

    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::sort(points.begin(), points.end(), compare);

    for (int i = 0; i < n; i++) {
        std::cout << points[i].x << ' ' << points[i].y << '\n';
    }

    return 0;
}
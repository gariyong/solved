// 문제: https://www.acmicpc.net/problem/2166
// 제목: 다각형의 면적

// 신발끈 공식을 사용
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef struct pair {
    double x, y;
} P;

double cross(P a, P b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    int n;
    cin >> n;

    vector<P> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double result = 0;

    for (int i = 0; i < n; i++) {
        result += cross(points[i], points[(i + 1) % n]);
    }

    result = abs(result) / 2.0;

    cout.precision(1);
    cout << fixed << result << '\n';

    return 0;
}
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n) {
    if (m > n) {
        swap(m, n);
    }
    int x = (m - 1) + (n - 1) * m;

    return x;
}
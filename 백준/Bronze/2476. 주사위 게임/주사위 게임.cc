#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int cost;
        if (a == b && b == c) {
            cost = 10000 + a * 1000;
        }
        else if (a == b || a == c) {
            cost = 1000 + a * 100;
        }
        else if (b == c) {
            cost = 1000 + b * 100;
        }
        else {
            cost = max({ a, b, c }) * 100;
        }

        result = max(result, cost);
    }

    cout << result;

    return 0;
}
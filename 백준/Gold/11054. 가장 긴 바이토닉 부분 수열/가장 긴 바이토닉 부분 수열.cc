#include <iostream>

using namespace std;

int num[1001];
int lis[1001];
int lds[1001];

int main() {
    int n;
    int max = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    for (int i = 1; i <= n; i++) {
        lis[i] = 1;
        for (int j = 1; j < i; j++) {
            if (num[j] < num[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        lds[i] = 1;
        for (int j = n; j > i; j--) {
            if (num[j] < num[i] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (max < lis[i] + lds[i] - 1) {
            max = lis[i] + lds[i] - 1;
        }
    }

    cout << max;

    return 0;
}
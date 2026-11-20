#include <iostream>

using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int x = 1;

    while (true) {
        int cnt = 0;

        for (int i = 0; i < 5; i++) {
            if (x % arr[i] == 0) {
                cnt++;
            }
        }

        if (cnt >= 3) {
            cout << x;
            break;
        }

        x++;
    }

    return 0;
}
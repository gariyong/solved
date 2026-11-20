#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++) {
        int space, star;

        if (i < n) {
            space = i;
            star = 2 * (n - i) - 1;
        } else {
            space = 2 * n - i - 2;
            star = 2 * (i - n + 1) + 1;
        }

        for (int j = 0; j < space; j++){
            cout << ' ';
        }
        
        for (int j = 0; j < star; j++){
            cout << '*';
        }
       
        cout << '\n';
    }

    return 0;
}
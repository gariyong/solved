#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int m = 0;
    int missing_index = -1;

    for (int i = 0; i < 13; i++) {
        if (s[i] == '*') {
            missing_index = i;
            continue;
        }
        if (i % 2 == 0) {
            m += s[i] - '0';
        }
        else {
            m += (s[i] - '0') * 3;
        }
    }

    int weight = (missing_index % 2 == 0) ? 1 : 3;

    for (int x = 0; x <= 9; x++) {
        if ((m + weight * x) % 10 == 0) {
            cout << x;

            return 0;
        }
    }

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int y1, m1, d1;
    int y2, m2, d2;

    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;

    int man_age = y2 - y1;
    if (m2 < m1 || (m2 == m1 && d2 < d1)) {
        man_age--;
    }

    int cnt_age = y2 - y1 + 1;

    int year_age = y2 - y1;

    cout << man_age << '\n';
    cout << cnt_age << '\n';
    cout << year_age << '\n';

    return 0;
}
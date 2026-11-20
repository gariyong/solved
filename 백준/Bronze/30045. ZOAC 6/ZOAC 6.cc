#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int cnt = 0;

    while (n--) {
        string s;
        cin >> s;

        bool found = false;

        for (int i = 0; i + 1 < (int)s.size(); ++i) {
            if ((s[i] == '0' && s[i + 1] == '1') ||
                (s[i] == 'O' && s[i + 1] == 'I')) {
                found = true;

                break;
            }
        }

        if (found) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;

    while (cin >> s >> t) {
        int s_idx = 0;
        int t_idx = 0;

        while (t_idx < t.length() && s_idx < s.length()) {
            if (t[t_idx] == s[s_idx]) {
                s_idx++;
            }
            t_idx++;
        }

        if (s_idx == s.length()) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
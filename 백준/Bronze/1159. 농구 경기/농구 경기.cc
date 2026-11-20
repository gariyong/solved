#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cnt[26] = { 0 };

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        
        cnt[name[0] - 'a']++;
    }

    bool found = false;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            cout << char(i + 'a');
            
            found = true;
        }
    }

    if (!found) cout << "PREDAJA\n";

    return 0;
}
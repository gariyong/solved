#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;

    while (true) {
        getline(cin, line);

        if (line == "#"){
          break;   
        }

        int count = 0;

        for (char c : line) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}

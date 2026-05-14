#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    int result = 1;

    for (auto x : clothes) {
        m[x[1]]++;
    }

    for(auto x : m) {
        result *= (x.second + 1);
    }

    return result - 1;
}
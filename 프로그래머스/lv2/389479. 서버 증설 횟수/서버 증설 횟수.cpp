#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int cnt = 0;
    vector<int> servers;
    int size = (int)servers.size();

    for (int i = 0; i < 24; i++) {
        if (players[i] >= m * (size + 1)) {
            int add_servers = (players[i] / m) - size;
            cnt += add_servers;
            size += add_servers;

            for (int j = 0; j < add_servers; j++) {
                servers.push_back(k);
            }
        }

        for (int j = size - 1; j >= 0; j--) {
            servers[j]--;

            if (servers[j] == 0) {
                servers.erase(servers.begin() + j);
                size--;
            }
        }
    }

    return cnt;
}
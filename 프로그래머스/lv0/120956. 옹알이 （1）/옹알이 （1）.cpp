#include <string>
#include <vector>

using namespace std;

void dfs(vector<string>& articul_case, const vector<string>& articulation, vector<bool>& used, string cur, int depth) {
    if (depth > 0 && depth <= 4) {
        articul_case.push_back(cur);
    }
    if (depth == 4) {
        return;
    }

    for (int i = 0; i < articulation.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            dfs(articul_case, articulation, used, cur + articulation[i], depth + 1);
            used[i] = false;
        }
    }
}

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> articulation = { "aya", "ye", "woo", "ma" };
    vector<string> articul_case;
    vector<bool> used(4, false);

    dfs(articul_case, articulation, used, "", 0);
    
    for (int i = 0; i < babbling.size(); i++) {
        for (int j = 0; j < articul_case.size(); j++) {
            if (babbling[i] == articul_case[j]) {
                answer++;
                break;
            }
        }
    }

    return answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> fibo;

void precompute_fibo() {
    fibo.push_back(0);
    fibo.push_back(1);

    while (true) {
        int next_fibo = fibo[fibo.size() - 1] + fibo[fibo.size() - 2];
        
        if (next_fibo > 1000000000) {
            break;
        }

        fibo.push_back(next_fibo);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;

    precompute_fibo();
	while (t--) {
        int n;
        cin >> n;

        vector<int> result;

        for (int i = (int)fibo.size() - 1; i >= 0; i--) {
            if (fibo[i] > n) continue;

			n -= fibo[i];
			result.push_back(fibo[i]);
			
            if (n == 0) break;
		}

		sort(result.begin(), result.end());
        for(int x : result) {
            cout << x << " ";
		}
        cout << '\n';
	}
}
#include <vector>
#include <iostream>

using namespace std;

bool prime[50001];

void is_prime() {
    fill(prime, prime + 50001, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 50000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 50000; j += i) {
                prime[j] = false;
            }
        }
    }
}

void backtrack(vector<int>& nums, int sum, int& cnt, int idx, int choose) {
    if (choose == 3) {
        if (prime[sum]) cnt++;
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        backtrack(nums, sum + nums[i], cnt, i + 1, choose + 1);
    }
}

int solution(vector<int> nums) {
    is_prime();
    int result = 0;
   
    backtrack(nums, 0, result, 0, 0);
    
    return result;
}
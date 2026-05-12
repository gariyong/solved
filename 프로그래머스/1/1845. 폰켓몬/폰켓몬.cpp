#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
	int size = nums.size();
	int n = size / 2;
	unordered_map<int, bool>m;

	for (int x : nums) {
		m.insert({ x, true });
	}

	return m.size() > n ? n : m.size();
}
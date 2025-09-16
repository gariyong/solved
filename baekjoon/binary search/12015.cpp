// 문제 : https://www.acmicpc.net/problem/12015
// 제목 : 가장 긴 증가하는 부분 수열 2

#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& arr, int x) {
	int left = 0;
	int right = (int)arr.size() - 1;
	int idx = (int)arr.size();

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] >= x) {
			idx = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	vector<int> nums(n);
	vector<int> subseq;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	subseq.push_back(nums[0]);
	for (int i = 1; i < n; i++) {
		if (subseq.back() < nums[i]) {
			subseq.push_back(nums[i]);
		}
		else {
			int idx = binary_search(subseq, nums[i]);
			subseq[idx] = nums[i];
		}
	}

	cout << subseq.size();

	return 0;
}
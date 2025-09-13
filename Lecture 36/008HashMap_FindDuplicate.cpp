// https://leetcode.com/problems/find-the-duplicate-number/description/

#include<iostream>
#include<vector>

using namespace std;

// time : O(n)
// space: O(1)

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		while (true) {
			int x = nums[0];
			if (nums[x] == x) {
				return x;
			}
			swap(nums[0], nums[x]);
		}
	}
};

int main() {

	vector<int> nums = {1, 3, 4, 2, 2};

	Solution s;
	cout << s.findDuplicate(nums) << endl;

	return 0;

}
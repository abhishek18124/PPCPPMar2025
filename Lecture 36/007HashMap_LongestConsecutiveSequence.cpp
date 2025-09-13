/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap;
		for (int x : nums) {
			// can x be a starting point of a sequence of consecutive elements ?
			if (startMap.find(x - 1) == startMap.end()) {
				// you've not seen x-1 so far so we can make x as a starting point for now
				startMap[x] = true;
			} else {
				// since we've seen x-1 so x cannot be a starting point
				startMap[x] = false;
			}
			if (startMap.find(x + 1) != startMap.end()) {
				// you've seen x+1 previously and now that you've seen x, x+1 can
				// no longer be a starting point
				startMap[x + 1] = false;
			}
		}

		// for (auto [el, canStart] : startMap) {
		// 	cout << el << " " << canStart << endl;
		// }

		int maxsofar = 0;

		for (pair<int, bool> p : startMap) {
			int key = p.first;
			bool canStart = p.second;
			if (canStart) {
				// find the length of the sequence of consecutive elements starting from key
				int cnt = 0;
				while (startMap.find(key) != startMap.end()) {
					cnt++;
					key++;
				}
				maxsofar = max(maxsofar, cnt);
			}
		}

		return maxsofar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {1, 2, 3, 5, 6, 7, 8, 10, 11};

	cout << s.longestConsecutive(nums) << endl;

}

// https://leetcode.com/problems/jump-game/
// 要注意走不下去就要return了

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int high = 0, n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (i <= high) {
				high = max(high, i+nums[i]);
				if (high >= n-1)
					return true;
			} else
				return false;
		}
		return false;
	}
};
// https://leetcode.com/problems/house-robber/
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<int> no(n+1, 0), yes(n+1, 0);
		for (int i = 1; i <= n; ++i) {
			no[i] = max(yes[i-1], no[i-1]);
			yes[i] = no[i-1] + nums[i-1];
		}
		return max(no[n], yes[n]);
	}
};
/*
# 复杂的递归解法：
class Solution {
public:
	int help(int now, int select, vector<int>& nums) {
		if (now == nums.size())
			return 0;
		if (select == 1)
			return help(now+1, 0, nums);
		int no = help(now+1, 0, nums), yes = help(now+1, 1, nums) + nums[now];
		return max(no, yes);
	}

	int rob(vector<int>& nums) {
		int no = help(0, 0, nums), yes = help(0, 1, nums);
		return max(no, yes);
	}
};
*/
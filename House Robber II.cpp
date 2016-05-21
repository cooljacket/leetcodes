// https://leetcode.com/problems/house-robber-ii/
// 将房子围成一个圈，（看了题解才想明白）首尾只能取一个，那就分别去掉去求，max一下就好了
// 注意特判一下size=0和1的情况

class Solution {
public:
	int helper(vector<int>& nums, int n) {
		vector<vector<int> > dp(n, vector<int>(2));
		dp[0][1] = nums[0];
		for (int i = 1; i < n; ++i) {
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
			dp[i][1] = dp[i-1][0] + nums[i];
		}
		return max(dp[n-1][0], dp[n-1][1]);
	}
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];
		vector<int> a(nums.begin(), nums.begin()+n-1);
		vector<int> b(nums.begin()+1, nums.end());
		int na = helper(a, n-1), nb = helper(b, n-1);
		return max(na, nb);
	}
};
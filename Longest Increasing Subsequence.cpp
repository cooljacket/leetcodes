// https://leetcode.com/problems/longest-increasing-subsequence/

// O(n^2)
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int n = nums.size();
		vector<int> dp(n, 1);
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j]+1);

		int longest = 0;
		for (int i = 0; i < n; ++i)
			longest = max(longest, dp[i]);
		return longest;
	}
};


// O(nlog n)
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int n = nums.size();
		vector<int> dp;
		vector<int>::iterator it;
		for (int i = 0; i < n; ++i) {
			it = lower_bound(dp.begin(), dp.end(), nums[i]);
			if (it != dp.end())
				//*it = min(*it, nums[i]);
				*it = nums[i];
			else
				dp.push_back(nums[i]);
		}
		/*for (int i = 0; i < dp.size(); ++i)
			printf("i=%d, dp=%d\n", i, dp[i]);*/
		return dp.size();
	}
};
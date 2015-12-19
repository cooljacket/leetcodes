// https://leetcode.com/problems/unique-binary-search-trees/
// 去了解一下卡特兰数？

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n+1, 0);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++i)
			for (int j = 0; j < i; ++j)
				dp[i] += dp[j] * dp[i-j-1];

		return dp[n];
	}
};
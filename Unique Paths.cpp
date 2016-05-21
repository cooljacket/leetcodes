// https://leetcode.com/problems/unique-paths/
// 大水题，棋盘型，(⊙o⊙)…比有障碍的小兵过河简单多了

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0)
			return 1;
		vector<vector<int> > dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
			dp[i][0] = 1;
		for (int j = 1; j < n; ++j)
			dp[0][j] = 1;
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				dp[i][j] += dp[i-1][j] + dp[i][j-1];
		return dp[m-1][n-1];
	}
};
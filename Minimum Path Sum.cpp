// https://leetcode.com/problems/minimum-path-sum/
// 经典棋盘型dp，大水题居然还排到了Medium的难度！！！

class Solution {
public:
	int minPathSum(vector<vector<int> >& grid) {
		if (grid.empty())
			return 0;
		int n = grid.size(), c = grid[0].size();
		for (int i = 1; i < n; ++i)
			grid[i][0] += grid[i-1][0];
		for (int j = 1; j < c; ++j)
			grid[0][j] += grid[0][j-1];
		for (int i = 1; i < n; ++i)
			for (int j = 1; j < c; ++j)
				grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
		return grid[n-1][c-1];
	}
};
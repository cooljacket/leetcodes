// https://leetcode.com/problems/maximal-square/
// 挺好玩的题目，从三个维度来做dp，其中v和h都是为了d服务的

class Solution {
public:
	int maximalSquare(vector<vector<char> >& matrix) {
		if (matrix.empty())
			return 0;
		int n = matrix.size(), c = matrix[0].size();
		// v垂直，h水平，d对角正方
		vector<vector<int> > v(matrix.size(), vector<int>(c)), d = v, h = v;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < c; ++j)
				if (matrix[i][j] == '1')
					v[i][j] = h[i][j] = d[i][j] = 1;

		for (int i = 1; i < n; ++i)
			for (int j = 1; j < c; ++j) {
				if (matrix[i][j] == '1') {
					v[i][j] = v[i-1][j] + 1;
					h[i][j] = h[i][j-1] + 1;
					d[i][j] = min(d[i-1][j-1], min(h[i][j-1], v[i-1][j])) + 1;
					//printf("i=%d, j=%d, v=%d, h=%d, d=%d\n", i, j, v[i][j], h[i][j], d[i][j]);
				}
			}

		int largest = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < c; ++j)
				largest = max(largest, d[i][j]);

		return largest*largest;
	}
};
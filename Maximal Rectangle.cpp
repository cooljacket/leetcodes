// https://leetcode.com/problems/maximal-rectangle/


class Solution {
public:
	int maximalRectangle(vector<vector<char> >& matrix) {
		if (matrix.empty())
			return 0;
		int n = matrix.size(), c = matrix[0].size(), largest = 0;
		// v垂直，h水平，d对角正方
		vector<vector<int> > v(n, vector<int>(c)), h = v;
		vector<vector<pair<int, int> > >d(n, vector<pair<int, int> >(c));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < c; ++j) {
				if (matrix[i][j] == '1') {
					v[i][j] = h[i][j] = d[i][j].first = d[i][j].second = 1;
					if (i >= 1)
						v[i][j] = v[i-1][j] + 1;
					if (j >= 1)
						h[i][j] = h[i][j-1] + 1;
					if (i >= 1 && j >= 1){
						d[i][j].first = min(d[i-1][j-1].first, h[i][j-1]) + 1;
						d[i][j].second = min(d[i-1][j-1].second, v[i-1][j]) + 1;	
					}
					
					if (v[i][j] > d[i][j].first * d[i][j].second)
						d[i][j].first = 1, d[i][j].second = v[i][j];
					if (h[i][j] > d[i][j].first * d[i][j].second)
						d[i][j].first = h[i][j], d[i][j].second = 1;
				}
				largest = max(largest, d[i][j].first * d[i][j].second);
			}

		return largest;
	}
};
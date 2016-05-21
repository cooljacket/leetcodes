// https://leetcode.com/problems/triangle
// 这道题的转移，我觉得是“反过来看”比较容易一点
// 就是遍历上层的每个点，它可以转移到下层的两个点
// 而不是站在下面一层去看可以由上面一层的哪个点到达它。
// 还有就是这个每一维的size不是固定的，而是1,2,3，...，这样子，一开始把n赋值为triangle[0].size()真是蠢哭了

class Solution {
public:
	int minimumTotal(vector<vector<int> >& triangle) {
		if (triangle.empty())
			return 0;

		int n = triangle.size();
		vector<int> dp(n, 0);
		dp[0] = triangle[0][0];
		for (int i = 1; i < n; ++i) {
			vector<int> tmp(n, 1e9);
			for (int j = 0; j < i; ++j) {
				tmp[j] = min(tmp[j], dp[j]+triangle[i][j]);
				tmp[j+1] = min(tmp[j+1], dp[j]+triangle[i][j+1]);
			}
			dp = tmp;
		}

		int minN = dp[0];
		for (int i = 1; i < n; ++i)
			minN = min(minN, dp[i]);
		return minN;
	}
};

/*
int main() {
	int n, tmp;
	cin >> n;
	vector<vector<int> > v(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j) {
			cin >> tmp;
			v[i].push_back(tmp);
		}

	return 0;
}
*/
/*
13
-7
-2 1
-5 -5 9
-4 -5 4 4
-6 -6 2 -1 -5
3 7 8 -3 7 -9
-9 -1 -9 6 9 0 7
-7 0 -6 -8 7 1 -4 9
-3 2 -6 -9 -7 -6 -9 4 0
-8 -6 -3 -9 -2 -6 7 -5 0 7
-9 -1 -2 4 -2 4 4 -1 2 -5 5
1 1 -6 1 -2 -4 4 -2 6 -6 0 6
-3 -3 -6 -2 -6 -2 7 -9 -5 -7 -5 5 1


2
1
2 3
*/


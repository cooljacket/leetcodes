// https://leetcode.com/problems/palindrome-partitioning-ii/
// O(n^2)，不需要用序列型的观点来看！因为回文的性质是“可以收缩”的！
// 对比一下矩阵链就知道，它一个点可以随意跟别的任意组合连乘，无论是向前还是向后，都可能最小
// 但是这里的回文可以一直看成是向前的！这样子问题就很明显了

class Solution {
public:
	int minCut(string s) {
		if (s.empty())
			return 0;

		int n = s.size();
		vector<vector<int> > dp(n, vector<int>(n, n));
		vector<vector<bool> > palin(n+1, vector<bool>(n+1, false));
		for (int i = 0; i < n; ++i)
			dp[i][i] = 1;

		s = ' ' + s;
		for (int i = n; i > 0; --i)
			for (int j = i; j <= n; ++j) {
				if (i == j)
					palin[i][j] = true;
				else if (s[i] == s[j])
					palin[i][j] = (j == i+1 || palin[i+1][j-1]);

				/*
				// 还可以更短地写：
				if (s[i] == s[j])
					palin[i][j] = (j < i+2 || palin[i+1][j-1]);
				*/
			}

		vector<int> cuts(n+1);
		for (int i = 1; i <= n; ++i) {
			cuts[i] = cuts[i-1] + 1;
			for (int j = 1; j < i; ++j)
				if (palin[j][i])
					cuts[i] = min(cuts[i], cuts[j-1]+1);
		}

		return cuts[n] - 1;
	}
};



// 这样写回文标志太不优雅了，参考下下面的！
int n = s.size();
vector<vector<int> > dp(n, vector<int>(n, n));
vector<vector<bool> > palin(n, vector<bool>(n, false));
for (int i = 0; i < n; ++i) {
	dp[i][i] = 1;
	palin[i][i] = true;
}
for (int i = 0; i < n; ++i) {
	int L = i-1, R = i+1;
	while (L >= 0 && R < n) {
		if (s[L] == s[R]) {
			palin[L][R] = true;
			--L;
			++R;
		} else break;
		//printf("Odd, L=%d, R=%d\n", L, R);
	}
}
for (int i = 0; i < n; ++i) {
	int L = i, R = i+1;
	while (L >= 0 && R < n) {
		if (s[L] == s[R]) {
			palin[L][R] = true;
			--L;
			++R;
		} else break;
		//printf("Even, L=%d, R=%d\n", L, R);
	}
}

// 优雅地写回文标志
int n = s.size();
vector<vector<int> > dp(n, vector<int>(n, n));
vector<vector<bool> > palin(n, vector<bool>(n, false));
for (int i = 0; i < n; ++i)
	dp[i][i] = 1;

for (int i = n-1; i >= 0; --i)
	for (int j = i; j < n; ++j) {
		if (i == j)
			palin[i][j] = true;
		else if (s[i] == s[j])
			palin[i][j] = (j == i+1 || palin[i+1][j-1]);
	}


// O(n^3)的做法会TLE
class Solution {
public:
	int minCut(string s) {
		if (s.empty())
			return 0;

		int n = s.size();
		vector<vector<int> > dp(n, vector<int>(n, n));
		vector<vector<bool> > palin(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i)
			dp[i][i] = 1;

		for (int i = n-1; i >= 0; --i)
			for (int j = i; j < n; ++j) {
				if (i == j)
					palin[i][j] = true;
				else if (s[i] == s[j])
					palin[i][j] = (j == i+1 || palin[i+1][j-1]);
			}

		for (int len = 2; len <= n; ++len)
			for (int left = 0; left+len <= n; ++left) {
				int right = left + len - 1;
				if (palin[left][right]) {
					dp[left][right] = 1;
					continue;
				}
				for (int k = left+1; k <= right; ++k)
					dp[left][right] = min(dp[left][right], dp[left][k-1] + dp[k][right]);
			}

		/*for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j)
				printf("i=%d, j=%d, palin=%d\n", i, j, (int)palin[i][j]);*/
		return dp[0][n-1] - 1;
	}
};

/*
adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece
*/
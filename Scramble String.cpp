// https://leetcode.com/problems/scramble-string/

// 想法挺奇妙的

class Solution {
public:
	bool isScramble(string s1, string s2) {
		/*string ss1(s1), ss2(s2);
		sort(ss1.begin(), ss1.end());
		sort(ss2.begin(), ss2.end());
		if (ss1 != ss2)
			return false;*/
		if (s1.size() != s2.size())
			return false;
		int L = s1.size();
		vector<vector<vector<bool> > > dp(L+1, vector<vector<bool> >(L, vector<bool>(L, false)));
		for (int len = 1; len <= L; ++len) {
			for (int i = 0; i+len <= L; ++i)
				for (int j = 0; j+len <= L; ++j) {
					if (len == 1)
						dp[len][i][j] = (s1[i] == s2[j]);
					else {
						for (int k = 1; k < len; ++k) {
							dp[len][i][j] = 
							(dp[k][i][j] && dp[len-k][i+k][j+k]) || (dp[k][i][j+len-k] && dp[len-k][i+k][j]);
							if (dp[len][i][j])
								break;						}
					}
					//printf("k=%d, i=%d, j=%d, dp=%d\n", len, i, j, (int)dp[len][i][j]);
				}
		}
		return dp[L][0][0];
	}
};
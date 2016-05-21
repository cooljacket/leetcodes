// https://leetcode.com/problems/interleaving-string/


class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int L1 = s1.size(), L2 = s2.size(), L3 = s3.size();
		if (L3 != L1 + L2)
			return false;

		s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
		vector<vector<bool> > match(L1+1, vector<bool>(L2+1, false));
		match[0][0] = true;
		for (int i = 0; i <= L1; ++i)
			for (int j = 0; j <= L2; ++j) {
				int k = i + j;
				if (k == 0)
					continue;
				if (s1[i] == s3[k])
					match[i][j] = match[i][j] || match[i-1][j];
				if (s2[j] == s3[k])
					match[i][j] = match[i][j] || match[i][j-1];
			}
		return match[L1][L2];
	}
};
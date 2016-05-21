// https://leetcode.com/problems/perfect-squares/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size(), ans = 0;
		vector<vector<int, int> > dp(n, vector<int>(n, 0));//, dp2 = dp;
		for (int len = 2; len < n; ++len)
			for (int left = 0; left+len <= n; ++left) {
				/*int right = left + len - 1, index = i, maxN = 0, now = 0;
				for (int i = left; i <= right; ++i)
					if (dp[index][i] > 0) {
						now += dp[index][i];
						maxN = max(maxN, now);
					} else {
						now = 0;
						index = i;
					}
				//dp2[left][right] = maxN;
				if (s[left] == '(' && s[right] == ')' && maxN == right-left-1) {
					dp[left][right] = right - left + 1;
					ans = max(ans, dp[left][right]);
				}*/
			}

		return ans;
	}
};


int main() {
	string s1;
	while (cin >> s1) {
		Solution s;
		cout << s.longestValidParentheses(s1) << endl;
	}
	
	return 0;
}

/*
(
)
()
(()
(())
(()())
()(()
()()
)(()())()()()))))(((()))))(()())()((()()))()()(())()()((()(())))()()(((((()())(((()))()())((())(())(((((()(())())(()()))())((()(((((()()(())))))))()))()()((()(()((()()((()()())(

*/
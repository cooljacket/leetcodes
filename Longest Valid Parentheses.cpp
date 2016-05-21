// https://leetcode.com/problems/longest-valid-parentheses/

// O(n), using stack...ref: http://www.cnblogs.com/easonliu/p/3637429.html
class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		vector<bool> good(s.size(), false);
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == ')' && !st.empty()) {
				good[st.top()] = good[i] = true;
				st.pop();
			} else if (s[i] == '(')
				st.push(i);

		int ans = 0, total = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (good[i])
				++total;
			else
				total = 0;
			ans = max(ans, total);
		}
		return ans;
	}
};

// O(n), using dp!!!
class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size(), ans = 0;
		s = ' ' + s;
		vector<int> dp(n+1, 0);
		for (int i = 2; i <= n; ++i) {
			if (s[i] == ')') {
				if (s[i-1] == '(')
					dp[i] = dp[i-2] + 2;
				else if (s[i-1] == ')') {
					int key = i - dp[i-1] - 1;
					if (key > 0 && s[key] == '(') {
						dp[i] = dp[i-1] + 2;
						if (key - 1 > 0)
							dp[i] += dp[key-1];
					}
				}
				ans = max(ans, dp[i]);
				//printf("i=%d, dp=%d, ans=%d\n", i, dp[i], ans);
			}
		}
		return ans;
	}
};

/*
(
)
()
(()
(())
(()())
()(()
()()
()(())
)(()())()()()))))(((()))))(()())()((()()))()()(())()()((()(())))()()(((((()())(((()))()())((())(())(((((()(())())(()()))())((()(((((()()(())))))))()))()()((()(()((()()((()()())(

*/
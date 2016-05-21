// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// 要求最多买卖两次
// 我想到的就是处理出前缀和后缀，再逐一枚举“分割点”就好了

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0 || n == 1)
			return 0;

		// assert n >= 2
		vector<int> dp(n+1), pre(n), post(n+1);
		int smallest = prices[0];
		for (int i = 1; i < n; ++i) {
			smallest = min(smallest, prices[i]);
			dp[i] = max(dp[i-1], prices[i]-smallest);
			pre[i] = max(pre[i-1], dp[i]);
			// printf("i=%d, dp=%d, pre=%d\n", i, dp[i], pre[i]);
		}

		int biggest = prices[n-1];
		for (int i = n-1; i >= 0; --i) {
			biggest = max(biggest, prices[i]);
			dp[i] = max(dp[i+1], biggest-prices[i]);
			post[i] = max(post[i+1], dp[i]);
			// printf("i=%d, dp=%d, pre=%d\n", i, dp[i], post[i]);
		}

		int largest = 0;
		for (int i = 0; i < n; ++i)
			largest = max(largest, pre[i]+post[i+1]);
		return largest;
	}
};

// ref: http://blog.csdn.net/linhuanmars/article/details/23236995
// 扩展到最多k次的最大收益！这种转移思考方式值得学习！
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;

		return helper(prices, 2);
	}

	int helper(vector<int>& prices, int k) {
		int n = prices.size(), largest = 0;
		vector<vector<int> > global(n, vector<int>(k+1)), local(global);
		for (int i = 1; i < n; ++i) {
			int diff = prices[i] - prices[i-1];
			for (int j = 1; j <= k; ++j) {
				local[i][j] = max(global[i-1][j-1]+max(diff, 0), local[i-1][j]+diff);
				global[i][j] = max(global[i-1][j], local[i][j]);
				largest = max(largest, global[i][j]);
			}
		}
		return largest;
	}
};
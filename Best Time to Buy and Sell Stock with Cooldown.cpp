// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// f[i]表示前i天处于自由状态（非冷却）且手里没股票，随时可以购买股票的最多的收益
// g[i]表示前i天手里买了股票的最大收益
// 初值的处理要注意好！这道题O(n^2)的做法会超空间，O(n)的算法是志锐启发我的，用了两个dp过程
/*
f[i]至少是f[i-1]，因为今天可以什么事都不干；还可以在前两天将手里的股票卖出去！
g[i]至少是g[i-1]，因为可以是在前面买的股票；也可以今天刚买的，为f[i]-prices[i]；
注意还要延伸多两个值，因为要多两天，才能覆盖到“最后一天卖掉股票”的情况。
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n < 2)
			return 0;

		prices.push_back(0);
		prices.push_back(0);
		n = prices.size();
		vector<int> f(n, 0), g(n, 0);
		f[0] = f[1] = 0;
		g[0] = -prices[0];
		g[1] = max(g[0], -prices[1]);
		for (int i = 2; i < n; ++i) { 
			f[i] = max(f[i-1], g[i-2]+prices[i-2]);
			g[i] = max(g[i-1], f[i]-prices[i]);
			// printf("i=%d, f=%d, g=%d\n", i, f[i], g[i]);
		}

		int lagest = 0;
		for (int i = 0; i < n; ++i)
			lagest = max(lagest, f[i]);
		return lagest;
	}
};
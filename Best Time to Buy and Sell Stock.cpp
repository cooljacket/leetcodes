// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
	// O(n^2) will lead to TLE
	/*
	int maxProfit(vector<int>& prices) {
		int maxP = -1;
		for (int i = 0; i < prices.size(); ++i)
			for (int j = i; j < prices.size(); ++j)
			maxP = max(maxP, prices[j]-prices[i]);
		return maxP;
	}
	*/
	int maxProfit(vector<int>& prices) {
		int maxP = 0, lowest = 1e9;
		for (int i = 0; i < prices.size(); ++i) {
			lowest = min(lowest, prices[i]);
			maxP = max(maxP, prices[i] - lowest);
		}
		return maxP;
	}
};
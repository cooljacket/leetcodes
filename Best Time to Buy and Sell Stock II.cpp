#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
给定一个价格数组，表示一只股票在每天的价格，求买卖股票赚的最大利润。

限制：手头还有股票没有卖出之前不允许买入。
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0, len = prices.size(), delta;
		for (int i = 1; i < len; ++i) {
			delta = prices[i] - prices[i-1];
			if (delta > 0)
				profit += delta;
		}
		return profit;
	}
};


int main() {
	int arr[] = {1, 3, 5, 2, 4};
	vector<int> prices = arr2vec(arr, 5);
	assert(Solution().maxProfit(prices) == 6);
	
	return 0;
}
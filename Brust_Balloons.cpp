/*************************************************************************
	> File Name: Brust_Balloons.cpp
	> Author: jacket
	> Mail: 
	> Created Time: 2015年12月11日 星期五 19时51分12秒
 ************************************************************************/
// https://leetcode.com/problems/burst-balloons/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int size = nums.size();
		nums.insert(nums.begin(), 1);
		nums.push_back(1);

		vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
		for (int len = 1; len <= size; ++len)
			for (int left = 1; left <= size-len+1; ++left) {
				int right = left + len - 1;
				for (int x = left; x <= right; ++x)
					dp[left][right] = max(dp[left][right], 
						dp[left][x-1] + nums[left-1]*nums[x]*nums[right+1] + dp[x+1][right]);
			}

		return dp[1][size];
	}
};

int main() {
	vector<int> nums(3, 6);
	Solution s;
	s.maxCoins(nums);
    return 0;
}
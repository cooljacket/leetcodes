// https://leetcode.com/problems/house-robber/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int len = nums.size();
        vector<vector<int> > dp(len+1, vector<int>(2, 0));
        for (int i = 0; i < len; ++i) {
        	dp[i+1][0] = max(dp[i][0], dp[i][1]);
        	dp[i+1][1] = dp[i][0] + nums[i];
        }
        return max(dp[len][0], dp[len][1]);
    }
};


int main() {
	Solution s;
	vector<int> nums;
	int n;
	while (cin >> n && n != 0)
		nums.push_back(n);

	cout << s.rob(nums) << endl;

	return 0;
}

/*
1 2 3 4 5 6 0
183 219 57 193 94 233 202 154 65 240 97 234 100 249 186 66 90 238 168 128 177 235 50 81 185 165 217 207 88 80 112 78 135 62 228 247 211
*/
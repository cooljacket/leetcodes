// https://leetcode.com/problems/maximum-subarray/
/*
// 二维的做法，不提倡
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pre(nums);
        for (int i = 1; i < nums.size(); ++i)
        	pre[i] += pre[i-1];

        pre.insert(pre.begin(), 0);
        int lagest = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        	for (int j = i; j < nums.size(); ++j)
        		lagest = max(lagest, pre[j+1]-pre[i]);
        return lagest;
    }
};
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local = nums[0], global = nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int largest = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            largest = max(largest, dp[i]);
        }
        return largest;
    }
};

/*
9
-2 1 -3 4 -1 2 1 -5 4

6
*/
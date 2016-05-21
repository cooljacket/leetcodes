// https://leetcode.com/problems/maximum-product-subarray/
// 注意乘法运算，状态转移的特殊性

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int n = nums.size();
		vector<int> big(n, nums[0]), small(n, nums[0]);
		for (int i = 1; i < n; ++i) {
			big[i] = max(max(big[i-1]*nums[i], nums[i]), small[i-1]*nums[i]);
			small[i] = min(min(small[i-1]*nums[i], nums[i]), big[i-1]*nums[i]);
		}
		int largest = big[0];
		for (int i = 1; i < n; ++i)
			largest = max(largest, big[i]);
		return largest;
	}
};
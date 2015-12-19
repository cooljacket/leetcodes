// 前缀数组而已，并不能算是dp吧
// https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
	vector<int> pre;
    NumArray(vector<int> &nums) {
    	int size = nums.size() + 1;
        pre = vector<int>(size, 0);
        for (int i = 1; i < size; ++i)
        	pre[i] = pre[i-1] + nums[i-1];
    }

    int sumRange(int i, int j) {
        return pre[j+1] - pre[i];
    }
};

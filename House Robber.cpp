#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;


class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int rob_it = 0, not_rob_it = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int rob_this = not_rob_it + nums[i];
			// if not rob this time, then at the lastest time you have two choices
			not_rob_it = max(rob_it, not_rob_it);
			// but if you choose to rob this time, the last time must be "not rob it"
			rob_it = rob_this;
		}

		return max(rob_it, not_rob_it);
	}
};


int main() {
	Solution s;
	vector<int> nums;
	s.rob(nums);

	return 0;
}
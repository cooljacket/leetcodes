#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
using namespace std;


class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> s;
		for (int i = 0; i < nums.size(); ++i)
			if (s.find(nums[i]) == s.end())
				s.insert(nums[i]);
			else
				return true;

		return false;
	}
};


int main() {
	Solution s;

	vector<int> nums;
	for (int i = 0; i < 10; ++i)
		nums.push_back(i);

	assert(s.containsDuplicate(nums) == false);

	nums[0] = 5;
	assert(s.containsDuplicate(nums) == true);

	return 0;
}
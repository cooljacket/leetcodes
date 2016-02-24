#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
using namespace std;


class Solution {
public:
	// the definition of the majortyElement maybe confused
	// because in {0, 0, 1, 1}, both 0 and 1 are the answer according to the description
	int majorityElement(vector<int>& nums) {
		int n = nums.size(), limit = (n + 1) / 2;

		map<int, int> cnt;
		for (int i = 0; i < n; ++i)
			++cnt[nums[i]];

		map<int, int>::iterator it = cnt.begin();
		while (it != cnt.end()) {
			if (it->second >= limit)
				return it->first;
			++it;
		}

		// must can't reach here
		return 0;
	}
};


int main() {
	Solution s;

	vector<int> nums;
	for (int i = 0; i < 10; ++i)
		nums.push_back(1);

	assert(s.majorityElement(nums) == 1);

	for (int i = 0; i < 5; ++i)
		nums[i] = 2;;
	assert(s.majorityElement(nums) == 1);

	nums.push_back(2);
	assert(s.majorityElement(nums) == 2);


	return 0;
}
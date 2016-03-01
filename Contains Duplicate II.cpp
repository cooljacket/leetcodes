#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;


class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> ms;
		for (int i = 0; i < nums.size(); ++i) {
			if (ms.find(nums[i]) == ms.end())
				ms[nums[i]] = i;
			else {
				if (i-ms[nums[i]] <= k)
					return true;
				ms[nums[i]] = i;
			}
		}

		return false;
	}
};

void print(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
		printf("%d ", nums[i]);
	printf("\n");
}


int main() {
	Solution s;

	vector<int> v;
	for (int i = 0; i < 12; ++i)
		v.push_back(i%5);

	print(v);
	assert(s.containsNearbyDuplicate(v, 3) == false);
	assert(s.containsNearbyDuplicate(v, 5) == true);

	return 0;
}
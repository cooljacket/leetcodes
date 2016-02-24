#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <assert.h>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int tail = nums.size() - 1;
		while (tail >= 0 && nums[tail] == 0)
			--tail;
		for (int i = tail-1; i >= 0; --i) {
			if (nums[i] == 0) {
				for (int j = i; j < tail; ++j)
					nums[j] = nums[j+1];
				nums[tail--] = 0;
			}
		}
	}
};

void print(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
		printf("%d\n", nums[i]);
	printf("\n");
}


int main() {
	Solution s;

	vector<int> nums;
	for (int i = 0; i < 10; ++i)
		nums.push_back(i);

	nums[5] = nums[3] = 0;

	s.moveZeroes(nums);
	print(nums);

	return 0;
}
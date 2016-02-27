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
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int len = 1, last = nums[0];
		for (int i = 1; i < nums.size(); ++i)
			if (nums[i] != last) {
				nums[len++] = nums[i];
				last = nums[i];
			}

		nums.resize(len);
		return len;
	}
};

void print(const vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");
}

int main() {
	Solution s;
	
	vector<int> v;
	for (int i = 0; i < 20; ++i)
		v.push_back(i / 4);

	print(v);
	s.removeDuplicates(v);
	print(v);

	return 0;
}
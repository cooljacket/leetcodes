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
	int removeElement(vector<int>& nums, int val) {
		vector<int> v;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != val)
				v.push_back(nums[i]);
		nums = v;

		return nums.size();
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
		v.push_back((i*i) % 5);

	print(v);
	s.removeElement(v, 0);
	print(v);

	s.removeElement(v, 1);
	print(v);

	return 0;
}
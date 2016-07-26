#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
把一个数组“左移”k位
*/
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k %= len;
		if (k == 0)
			return;
		rotateHelper(nums, 0, len - k);
		rotateHelper(nums, len - k, len);
		rotateHelper(nums, 0, len);
	}

private:
	void rotateHelper(vector<int>& nums, int begin, int end) {
		for (int i = begin, j = end - 1; i < j; ++i, --j)
			swap(nums[i], nums[j]);
	}
};


int main() {
	
	return 0;
}
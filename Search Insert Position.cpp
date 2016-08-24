#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
#include "headers/TreeNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;
typedef TreeNodeTemplate<int> TreeNode;


/*
问题要求：
给定一个排好序的数组（升序）和一个数字target。
1）如果target在数组里，返回它的位置；
2）否则返回它插入到数组后保持数组有序的位置。
*/
class Solution {
public:
	// 思路：线性扫描或者二分法
	/*
	// 1）线性扫描
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size(), pos = len - 1;
		while (pos >= 0 && nums[pos] >= target) {
			if (nums[pos] == target)
				return pos;
			--pos;
		}
		return pos + 1;
	}*/

	// 2）二分法！注意分析最后为什么是right + 1，找不到分三种情况～
	// a) 从左边溢出区间；b）从右边溢出区间；c）陷于区间上两个相邻的值之间。
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return right + 1;
	}
};


int main() {
	int arr[] = {1, 3, 5, 6};
	vector<int> vec = arr2vec(arr, 4);
	assert(Solution().searchInsert(vec, 5) == 2);
	assert(Solution().searchInsert(vec, 2) == 1);
	assert(Solution().searchInsert(vec, 7) == 4);
	assert(Solution().searchInsert(vec, 0) == 0);
	
	return 0;
}
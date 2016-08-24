#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
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
在一个排序数组里按某个元素翻转后得到的数组，比如0 1 2 4 5 6 7可变成4 5 6 7 0 1 2。
假设输入的数组没有重复的元素
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		int low = 0, high = nums.size() - 1, mid;
		while (low < high) {
			mid = (low + high) >> 1;
			if (nums[mid] > nums[high])
				low = mid + 1;
			else
				high = mid;
		}
		return nums[low];
	}
};


int main() {
	int arr1[] = {4, 5, 6, 7, 0, 1, 2};
	vector<int> vec1 = arr2vec(arr1, 7);
	assert(Solution().findMin(vec1) == 0);

	int arr2[] = {2, 1};
	vector<int> vec2 = arr2vec(arr2, 2);
	assert(Solution().findMin(vec2) == 1);

	int arr3[] = {2, 3, 4, 0, 1};
	vector<int> vec3 = arr2vec(arr3, 5);
	assert(Solution().findMin(vec3) == 0);

	int arr4[] = {1, 2, 3, 4};
	vector<int> vec4 = arr2vec(arr4, 4);
	assert(Solution().findMin(vec4) == 1);

	return 0;
}
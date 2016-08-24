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
摆动排序，把数组排列成a1 < a2 > a3 < a4 > ...的形式，输入保证有解
参考：http://bookshadow.com/weblog/2015/12/31/leetcode-wiggle-sort-ii/
*/
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> cp(nums);
		int len = nums.size(), mid = (len - 1) >> 1;
		for (int i = 0; i <= mid; ++i) {
			int index = i << 1;
			nums[index] = cp[mid-i];
			if (++index < len)
				nums[index] = cp[len-i-1];
		}
	}
};


int main() {
	int arr1[] = {1,5,1,1,6,4};
	vector<int> nums1 = arr2vec(arr1, 6);
	Solution().wiggleSort(nums1);
	display_v(nums1);

	int arr2[] = {1,3,2,2,3,1};
	vector<int> nums2 = arr2vec(arr2, 6);
	Solution().wiggleSort(nums2);
	display_v(nums2);

	int arr3[] = {1,5,1,6,4};
	vector<int> nums3 = arr2vec(arr3, 5);
	Solution().wiggleSort(nums3);
	display_v(nums3);

	return 0;
}
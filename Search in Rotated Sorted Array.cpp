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
旋转有序数组：在一个排序数组里按某个元素翻转后得到的数组，比如0 1 2 4 5 6 7可变成4 5 6 7 0 1 2。
假设输入的数组没有重复的元素

在这样的数组里查找
*/

// 递归做法
// class Solution {
// public:
// 	int search(vector<int>& nums, int target) {
// 		return searchHelper(nums, 0, nums.size()-1, target);
// 	}

// private:
// 	int searchHelper(const vector<int>& nums, int low, int high, int target) {
// 		// cout << low << ' ' << high << endl;
// 		if (low > high)
// 			return -1;
// 		int mid = (low + high) >> 1;
// 		if (nums[mid] == target)
// 			return mid;
// 		if (nums[high] >= nums[low]) {
// 			if (nums[mid] > target)
// 				return searchHelper(nums, low, mid - 1, target);
// 			else
// 				return searchHelper(nums, mid + 1, high, target);
// 		} else {
// 			int resultA = searchHelper(nums, low, mid - 1, target);
// 			if (resultA != -1)
// 				return resultA;
// 			return searchHelper(nums, mid + 1, high, target);
// 		}
// 	}
// };

// 迭代做法
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1, mid;
		while (low < high) {
			mid = (low + high) >> 1;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] < nums[high]) {
				if (target > nums[mid] && target <= nums[high])
					low = mid + 1;
				else
					high = mid - 1;
			} else {
				if (target >= nums[low] && target < nums[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
		}
		return nums[low] == target ? low : -1;
	}
};


int main() {
	int arr1[] = {5, 6, 7, 0, 1, 2, 3, 4};
	vector<int> vec1 = arr2vec(arr1, 8);
	for (int i = 0; i < 8; ++i) {
		int pos = Solution().search(vec1, i);
		if (pos == -1)
			cout << "Not found" << endl;
		else
			cout << "Found: " << i << ' ' << arr1[pos] << endl;
	}
	cout << "search " << 233 << ' ' << Solution().search(vec1, 233) << endl;
	cout << "search " << -100 << ' ' << Solution().search(vec1, -100) << endl;

	int arr2[] = {3, 1};
	vector<int> vec2 = arr2vec(arr2, 2);
	assert(Solution().search(vec2, 1) == 1);
	assert(Solution().search(vec2, 3) == 0);

	return 0;
}
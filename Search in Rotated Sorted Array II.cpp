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

*/
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1, mid;
		while (low < high) {
			mid = (low + high) >> 1;
			if (nums[mid] == target)
				return true;
			if (nums[mid] < nums[high]) {
				if (target > nums[mid] && target <= nums[high])
					low = mid + 1;
				else
					high = mid - 1;
			} else if (nums[mid] > nums[high]) {
				if (target >= nums[low] && target < nums[mid])
					high = mid - 1;
				else
					low = mid + 1;
			} else {
				--high;
			}
		}
		return nums[low] == target;
	}
};



int main() {
	int arr1[] = {5, 6, 7, 0, 1, 2, 3, 4};
	vector<int> vec1 = arr2vec(arr1, 8);
	for (int i = 0; i < 8; ++i) {
		assert(Solution().search(vec1, i));
	}
	assert(Solution().search(vec1, 233) == false);
	assert(Solution().search(vec1, -100) == false);

	int arr2[] = {3, 1};
	vector<int> vec2 = arr2vec(arr2, 2);
	assert(Solution().search(vec2, 1) == true);
	assert(Solution().search(vec2, 3) == true);
	

	return 0;
}
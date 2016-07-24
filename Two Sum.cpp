#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
给定一个数组和一个目标值target，要求在数组里找到两个数字，其和刚好等于target。
测试数据保证恰好有一个解。

注意，返回的是一个有两个元素的数组，分别代表这两个数字在原数组的下标
*/
class Solution {
public:
	// 思路：1）最简单的方法就是，对于每个元素，都向后搜索一遍，时间复杂度为O(n^2)；
	// 2）改进的话，可以考虑将数组排序，然后同时从左右两边扫描！！！时间复杂度由排序算法决定；
	// 3）但是，这里要求返回的是元素在原数组的下标，所以用2）的方法就得维护多一个下标；
	// 4）还不如直接把所有元素放进哈希表或map里，然后遍历查找target - x，时间复杂度为O(nlog n)。
	// 5) 对于数组里有多个相同的元素，为什么这样做还是可以的呢？因为解是唯一的，如果target = 2*x，
	// 那么说明数组里恰好有两个x，必定有先后顺序，后者会把map里的前者的下标覆盖，而遍历的时候是从前到后，
	// 所以两者刚好匹配～（看main函数里提供的第三个例子）
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, size_t> m;
		for (size_t i = 0; i < nums.size(); ++i) {
			m[nums[i]] = i;
		}

		vector<int> ans(2, 0);
		map<int, size_t>::iterator it;
		for (size_t i = 0; i < nums.size(); ++i) {
			it = m.find(target - nums[i]);
			// 注意去掉自己加上自己等于target的这种情况
			if (it != m.end() && it->second != i) {
				ans[0] = i;
				ans[1] = it->second;
				break;
			}
		}
		return ans;
	}
};


int main() {
	int arr[] = {2, 7, 11, 15};
	vector<int> nums = arr2vec(arr, 4);
	vector<int> ans = Solution().twoSum(nums, 9);
	display_v(ans);
	

	int arr2[] = {3, 2, 4};
	vector<int> nums2 = arr2vec(arr2, 3);
	vector<int> ans2 = Solution().twoSum(nums2, 6);
	display_v(ans2);


	int arr3[] = {3, 2, 2};
	vector<int> nums3 = arr2vec(arr3, 3);
	vector<int> ans3 = Solution().twoSum(nums3, 4);
	display_v(ans3);

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
给一个数组，对于每个元素，输出数组里其它元素的乘积。比如：
[1,2,3,4] -> [24,12,8,6]
*/
class Solution {
public:
	// 思路：除自己以外的所有乘积，分解成：前面的所有元素的乘积 * 后面的所有元素的乘积
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size(), product_head = 1, product_tail = 1;
		vector<int> products(len);
		for (int i = 0; i < len; ++i) {
			products[i] = product_head;
			product_head *= nums[i];
		}

		for (int i = len - 1; i >= 0; --i) {
			products[i] *= product_tail;
			product_tail *= nums[i];
		}

		return products;
	}
};



int main() {
	int arr[] = {1, 2, 3, 4};
	vector<int> nums = arr2vec(arr, 4);
	vector<int> res = Solution().productExceptSelf(nums);
	display_v(res);

	return 0;
}
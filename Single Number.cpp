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
给定一个数组，里面除了一个元素之外，其它都恰好出现了两次，找出只出现一次的数字
*/
class Solution {
public:
	// 思路：使用异或运算酒搞定了
	int singleNumber(vector<int>& nums) {
		int x = 0;
		for (int i = 0; i < nums.size(); ++i)
			x = x ^ nums[i];
		return x;
	}
};


int main() {
	int arr[] = {2, 3, 2, 1, 3};
	vector<int> nums = arr2vec(arr, 5);
	cout << Solution().singleNumber(nums) << endl;
	return 0;
}
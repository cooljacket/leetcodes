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
#include "headers/TreeNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;
typedef TreeNodeTemplate<int> TreeNode;


/*
问题要求：
给定一个数组，里面有n个数字，范围是[0, n]，每个最多出现一次，求没有出现的那个数字！！！

限制：线性时间，最好也用常数空间！
*/
class Solution {
public:
	// 其实还是异或运算的小把戏～还可以考虑加法，但是加法可能会超过int的范围，用异或最保险
	int missingNumber(vector<int>& nums) {
		int x_or = 0, n = nums.size();
		for (int i = 0; i <= n; ++i)
			x_or = x_or ^ i;
		for (int i = 0; i < n; ++i)
			x_or = x_or ^ nums[i];
		return x_or;
	}
};


int main() {
	int arr[] = {3, 0, 1};
	vector<int> vec = arr2vec(arr, 3);
	assert(Solution().missingNumber(vec) == 2);
	
	return 0;
}
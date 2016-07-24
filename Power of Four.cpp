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
判断一个整数是不是4的次方

更多限制：试试不用循环和递归来做？
*/
class Solution {
public:
	// 思路，首先num肯定是得大于0的，其次，它的二进制形式里必定只有一个位置为1，其它都是0
	// 并且，这个位置肯定是在奇数位！
	// 注意num & (num-1)的意义，它如果为零，表示num肯定是2的次方，不信可以自己推导～
	bool isPowerOfFour(int num) {
		return num > 0 && (num & (num-1)) == 0 && (num & 0x55555555) != 0;
	}
};


int main() {
	Solution s;
	assert(s.isPowerOfFour(4) == true);
	assert(s.isPowerOfFour(16) == true);
	assert(s.isPowerOfFour(233) == false);

	return 0;
}
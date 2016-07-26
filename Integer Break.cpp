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
将一个整数n(2 <= n <= 58)，拆分成两个或两个以上的数字的和，要求这些数字的乘积的最大值
*/
class Solution {
public:
	// 思路：找规律的题目咕~~(╯﹏╰)b，估计要严格证明够呛
	int integerBreak(int n) {
		if (n == 2 || n == 3)
			return n - 1;
		int res = 1;
		while (n > 4) {
			res *= 3;
			n -= 3;
		}
		return res * n;
	}
};


int main() {
	assert(Solution().integerBreak(7) == 12);
	assert(Solution().integerBreak(8) == 18);
	assert(Solution().integerBreak(9) == 27);
	assert(Solution().integerBreak(10) == 36);
	
	return 0;
}
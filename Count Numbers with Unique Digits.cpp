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
计数，计算[0, 10^n)里，有多少个数字，它的（十进制形式）各个位置上的数字互不相同
*/
class Solution {
public:
	// 其实是简单的排列题目
	// Let f(k) = count of numbers with unique digits with length equals k.
	// f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
			return 1;
		int now = 9, ans = 10;
		for (int i = 1; i < n; ++i) {
			now *= 10 - i;
			ans += now;
		}
		return ans;
	}
};


int main() {
	assert(Solution().countNumbersWithUniqueDigits(0) == 1);
	assert(Solution().countNumbersWithUniqueDigits(1) == 10);
	assert(Solution().countNumbersWithUniqueDigits(2) == 91);
	
	return 0;
}
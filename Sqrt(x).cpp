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
求x的平方根的整数近似值
*/
class Solution {
public:
	int mySqrt(int x) {
		// 牛顿法超级快
		long long r = x;
		while (r*r > x) {
			r = (r + x/r) >> 1;
		}
		return r;

		// 甩二分法三条街！
		// if (x < 0)
		// 	return 0;
		// long long low = 0, high = x, mid;
		// while (low < high) {
		// 	mid = (low + high + 1) >> 1;
		// 	long long key = mid * mid;
		// 	if (key == x)
		// 		return mid;
		// 	else if (key > x)
		// 		high = mid - 1;
		// 	else
		// 		low = mid;
		// }
		// return low;
	}
};


int main() {
	assert(Solution().mySqrt(3) == 1);
	assert(Solution().mySqrt(4) == 2);
	assert(Solution().mySqrt(13) == 3);
	assert(Solution().mySqrt(101) == 10);
	assert(Solution().mySqrt(2147395599) == 46339);

	return 0;
}
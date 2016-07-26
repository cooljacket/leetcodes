#include <iostream>
#include <stdio.h>
#include <cmath>
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
初始有n个灯泡，都是关着的，编号从1到n。
在第i轮，需要将编号能被i整除的编号的灯泡的状态反转，即关变开，开变关。
求n轮过后，还有多少个灯泡亮着

实践证明，模拟会超时，还是得用数学的方法。
*/
class Solution {
public:
	// 思路：只有因子个数为奇数的编号才会在最后亮着，这些数字必定是完全平方数，所以。
	int bulbSwitch(int n) {
		return sqrt(n);
	}
};


int main() {
	assert(Solution().bulbSwitch(3) == 1);
	assert(Solution().bulbSwitch(99999) == 316);
	assert(Solution().bulbSwitch(9999999) == 3162);
	
	return 0;
}
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
给定一个数字num，找出[0, num]上所有数字的二进制形式的1的个数
*/
class Solution {
public:
	vector<int> countBits(int num) {
		int len = num + 1;
		vector<int> bits(len);
		for (int i = 0; i < len; ++i)
			bits[i] = getBits(i);
		return bits;
	}

private:
	int getBits(int x) {
		int ans = 0;
		while (x > 0) {
			++ans;
			x = x & (x - 1);
		}
		return ans;
	}
};


int main() {
	vector<int> bits = Solution().countBits(5);
	display_v(bits);
	return 0;
}
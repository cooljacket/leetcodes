#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
把一个整数转化成Excel的列号的格式，即：

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/
class Solution {
public:
	// 思路：看代码吧，搞清楚进制
	string convertToTitle(int n) {
		string ans;
		while (n > 0) {
			int key = n % 26;
			if (key == 0)
				key = 26;
			n = (n - key) / 26;
			ans += 'A' + key - 1;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};


int main() {
	assert(Solution().convertToTitle(1) == "A");
	assert(Solution().convertToTitle(2) == "B");
	assert(Solution().convertToTitle(26) == "Z");
	assert(Solution().convertToTitle(26*27) == "ZZ");
	assert(Solution().convertToTitle(26*27+1) == "AAA");
	return 0;
}
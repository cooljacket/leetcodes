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
对字符串做zig-zag变换
*/
class Solution {
public:
	// 其实是纯粹找规律的题目，得先懂zig-zag到底是什么，之后就很容易了
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int len = s.size(), halfKey = numRows-1, key = 2 * halfKey;
		string zz;
		for (int i = 0; i < numRows; ++i) {
			int j = 0, neighbor, now;
			while ((now = (j++)*key+i) < len) {
				zz.push_back(s[now]);
				neighbor = now + key - 2*i;
				if (i != 0 && neighbor != now && neighbor < len)
					zz.push_back(s[neighbor]);
			}
		}
		return zz;
	}
};


int main() {
	assert(Solution().convert("PAYPALISHIRING", 3) == string("PAHNAPLSIIGYIR"));
	assert(Solution().convert("A", 1) == "A");
	assert(Solution().convert("ABCD", 2) == "ACBD");
	assert(Solution().convert("ABCDE", 4) == "ABCED");

	return 0;
}
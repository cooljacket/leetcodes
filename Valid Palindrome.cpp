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
给定一个句子，忽略字母大小写，只考虑里面的字母或数字，标点符号不管，判断是否为回文串
*/
class Solution {
public:
	// 思路：其实也是非常简单的问题，“走”到下一个位置需要while循环来找而已
	bool isPalindrome(string s) {
		int len = s.size(), left = -1, right = len;
		while (++left < --right) {
			while (left <= right && !checkAndRevise(s[left]))
				++left;
			while (right >= left && !checkAndRevise(s[right]))
				--right;
			if (left <= right && s[left] != s[right])
				return false;
		}
		return true;
	}

	bool checkAndRevise(char& ch) {
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch - 'A' + 'a';
			return true;
		}
		if (ch >= 'a' && ch <= 'z')
			return true;
		return ch >= '0' && ch <= '9';
	}
};


int main() {
	assert(Solution().isPalindrome("A man, a plan, a canal: Panama") == true);
	assert(Solution().isPalindrome("race a car") == false);
	return 0;
}
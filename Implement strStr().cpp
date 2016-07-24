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
在字符串haystack中查找子串needle，返回第一次出现的位置，否则返回-1
*/
class Solution {
public:
	// 思路：其实是经典的子串匹配问题
	// 1）最简单的暴力匹配，时间复杂度为O(MN)；
	// 2）KMP算法可以达到O(M+N)
	// 3）还有很多黑科技，有兴趣可以google之～
	int strStr(string haystack, string needle) {
		return KMP().KMP_match(haystack, needle);
	}

	class KMP {
	private:
		vector<int> next;

	public:
		int KMP_match(const string& text, const string& pattern) {
			calNextArray(pattern);
			int t = -1, p = -1, tLen = text.size(), pLen = pattern.size();
			while (t < tLen && p < pLen) {
				if (p == -1 || text[t] == pattern[p])
					++p, ++t;
				else
					p = next[p];
			}
			return (p == pLen) ? (t - pLen) : -1;
		}

	private:
		// 计算next数组的过程，其实就是自己KMP匹配自己的过程！
		void calNextArray(const string& pattern) {
			int pLen = pattern.size(), pre = -1, post = 0;
			next = vector<int>(pLen, -1);
			while (post < pLen - 1) {
				if (pre == -1 || pattern[post] == pattern[pre]) {
					++pre, ++post;
					if (pattern[post] != pattern[pre])
						next[post] = pre;
					else
						next[post] = next[pre];
				} else
					pre = next[pre];
			}
		}
	};
};


int main() {
	cout << Solution().strStr("abacababc", "abab") << endl;
	cout << Solution().strStr("hello world!", "jacket") << endl;
	cout << Solution().strStr("ABCABCAABCABDE", "ABCABD") << endl;

	return 0;
}
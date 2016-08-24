#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
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
给定一个单词数组，要求找出里面两个没有相同字母的单词，使得它们的长度的乘积最大，如果不存在则返回0.

ps，单词只含小写字母。
*/
class Solution {
public:
	// 思路：白痴做法，用bool数组会超时，改用位运算就超级快！
	int maxProduct(vector<string>& words) {
		int len = words.size();
		vector<int> features(len, 0);
		for (int i = 0; i < len; ++i)
			genFeture(words[i], features[i]);

		int maxN = 0;
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; ++j)
				if ((features[i] & features[j]) == 0)
					maxN = max(maxN, (int) (words[i].size() * words[j].size()));
		}
		return maxN;
	}

	void genFeture(const string& word, int& feature) {
		int len = word.size();
		for (int i = 0; i < len; ++i)
			feature |= 1 << (word[i] - 'a');
	}
};


int main() {
	string arr1[] = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	vector<string> words1 = arr2vec(arr1, 6);
	assert(Solution().maxProduct(words1) == 16);


	string arr2[] = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
	vector<string> words2 = arr2vec(arr2, 7);
	assert(Solution().maxProduct(words2) == 4);


	string arr3[] = {"a", "aa", "aaa", "aaaa"};
	vector<string> words3 = arr2vec(arr3, 4);
	assert(Solution().maxProduct(words3) == 0);
	
	return 0;
}
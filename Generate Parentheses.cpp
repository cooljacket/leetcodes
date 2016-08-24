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
给定一个整数n表示括号的对数，要求生成所有由n对括号组成的合法括号序列，比如n=3时，有：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
	// 思路：其实就是非常简单的dfs
	vector<string> generateParenthesis(int n) {
		vector<string> seq_list;
		string seq(2*n, ' ');
		helper(n, 0, 0, seq, seq_list);
		return seq_list;
	}

private:
	void helper(int n, int leftCnt, int rightCnt, string& now, vector<string>& seq_list) {
		if (leftCnt == n && rightCnt == n) {
			seq_list.push_back(now);
			return;
		}

		if (leftCnt < n) {
			now[leftCnt+rightCnt] = '(';
			helper(n, leftCnt + 1, rightCnt, now, seq_list);
		}

		if (rightCnt < n && rightCnt < leftCnt) {
			now[leftCnt+rightCnt] = ')';
			helper(n, leftCnt, rightCnt+1, now, seq_list);
		}
	}
};


int main() {
	vector<string> seq_list = Solution().generateParenthesis(3);
	display_v(seq_list, '\n');
	
	return 0;
}
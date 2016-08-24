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
给定两个字符串A、B，B中的每个字符最多只能用一次，问能否构成A

可以认为AB中都只含有小写字母
*/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> count(26);
		for (int i = magazine.size()-1; i >= 0; --i) {
			++count[char2int(magazine[i])];
		}
		for (int i = ransomNote.size()-1; i >= 0; --i) {
			if (--count[char2int(ransomNote[i])] < 0)
				return false;
		}
		return true;
	}

	int char2int(char ch) {
		return ch - 'a';
	}
};


int main() {
	string a, b;
	while (cin >> a >> b) {
		cout << Solution().canConstruct(a, b) << endl;
	}

	return 0;
}
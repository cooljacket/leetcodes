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
找出字符串里第一个唯一出现过的字母的位置，没有则返回-1

注：可以认为字符串里只含小写字母
*/
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> occur(26, 0);
		int size = s.size();
		for (int i = 0; i < size; ++i) {
			++occur[ char2int(s[i]) ];
		}
		for (int i = 0; i < size; ++i) {
			if (occur[ char2int(s[i]) ] == 1)
				return i;
		}
		return -1;
	}

	int char2int(char ch) {
		return ch - 'a';
	}
};


int main() {
	string s;
	while (cin >> s) {
		cout << s << ' ' << Solution().firstUniqChar(s) << endl;
	}

	return 0;
}
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
要求按照镜像构建法产生格雷码，参考：
https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81#/media/File:Binary-reflected_Gray_code_construction.svg
*/
class Solution {
public:
	// 镜像构建法很容易理解，就是每次对称复制一遍，然后在后半部分的开头的最高位“+1”
	// 注意n=0的情况是返回{0}
	vector<int> grayCode(int n) {
		vector<int> allCodes;
		allCodes.push_back(0);
		for (int i = 1; i <= n; ++i) {
			vector<int> mirror(allCodes.rbegin(), allCodes.rend());
			int mask = 1 << (i-1);
			for (int j = 0; j < allCodes.size(); ++j) {
				mirror[j] = mask | mirror[j];
			}
			allCodes.insert(allCodes.end(), mirror.begin(), mirror.end());
		}
		return allCodes;
	}
};



int main() {
	vector<int> allCodes1 = Solution().grayCode(1);
	display_v(allCodes1);
	cout << endl;

	vector<int> allCodes2 = Solution().grayCode(2);
	display_v(allCodes2);
	cout << endl;

	vector<int> allCodes3 = Solution().grayCode(3);
	display_v(allCodes3);
	cout << endl;

	return 0;
}
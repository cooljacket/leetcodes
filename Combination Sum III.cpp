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
给定数字的个数k和总和n，要求从[1-9]中选取k个各不相同的数字组合，其总和刚好等于n，返回所有组合情况
*/
class Solution {
public:
	vector<vector<int> > combinationSum3(int k, int n) {
		vector<vector<int> > ans;
		vector<int> v;
		dfs(0, 0, k, n, v, ans);
		return ans;
	}

private:
	void dfs(int last, int sum, int k, int n, vector<int>& v, vector<vector<int> >& ans) {
		if (k - v.size() == 1) {
			int key = n - sum;
			if (key > last && key <= 9) {
				v.push_back(key);
				ans.push_back(v);
				v.pop_back();
			}
			return;
		}

		for (int i = last+1; i <= 9; ++i) {
			int numToFill = k - v.size();
			// 注意后半部分的表达式，其实是计算等差数列的公式: sum(a, a+1, ..., a+num-1)
			// futureSum表示如果要将i作为下一个的话，未来的和至少是多少！以此来剪枝
			int futureSum = sum + ((i + i + numToFill - 1) * numToFill) / 2;
			if (futureSum > n)
				break;
			v.push_back(i);
			dfs(i, sum + i, k, n, v, ans);
			v.pop_back();
		}
	}
};


int main() {
	vector<vector<int> > matrix1 = Solution().combinationSum3(3, 7);
	display_m(matrix1);
	cout << endl;

	vector<vector<int> > matrix2 = Solution().combinationSum3(3, 9);
	display_m(matrix2);
	cout << endl;
	
	return 0;
}
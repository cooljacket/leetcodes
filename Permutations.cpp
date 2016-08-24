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
按字典序生成全排列
*/

// 用的是递归的方法，还有别的吗？
class Solution {
public:
	vector<vector<int> > permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > permutations;
		vector<int> copy(nums);
		vector<bool> have(nums.size());
		dfs(nums, copy, have, permutations, -1);
		return permutations;
	}

private:
	void dfs(const vector<int>& sorted, vector<int>& nums, vector<bool>& have, vector<vector<int> >& permutations, int count) {
		if (++count == nums.size()) {
			permutations.push_back(nums);
			return;
		}

		for (int i = 0; i < sorted.size(); ++i) {
			if (!have[i]) {
				nums[count] = sorted[i];
				have[i] = true;
				dfs(sorted, nums, have, permutations, count);
				have[i] = false;
			}
		}
	}
};



int main() {
	int arr1[] = {1, 2, 3};
	vector<int> vec1 = arr2vec(arr1, sizeof(arr1)/sizeof(int));
	vector<vector<int> > matrix = Solution().permute(vec1);
	display_m(matrix);

	return 0;
}
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
给定一个升序的数组，将其转成平衡二叉搜索树
*/

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return buildBSTHelper(nums, 0, nums.size() - 1);
	}

private:
	TreeNode* buildBSTHelper(const vector<int>& nums, int begin, int end) {
		if (begin > end)
			return NULL;
		int mid = (begin + end) >> 1;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = buildBSTHelper(nums, begin, mid-1);
		root->right = buildBSTHelper(nums, mid+1, end);
		return root;
	}
};

int main() {
	int arr1[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int> nums1 = arr2vec(arr1, 7);
	TreeNode* root1 = Solution().sortedArrayToBST(nums1);
	display_tree(root1);

	int arr2[] = {3, 5, 8};
	vector<int> nums2 = arr2vec(arr2, 3);
	TreeNode* root2 = Solution().sortedArrayToBST(nums2);
	display_tree(root2);
	
	return 0;
}
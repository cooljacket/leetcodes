#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
	void setLeft(TreeNode* L) {
		left = L;
	}
	void setRight(TreeNode* R) {
		right = R;
	}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	/*
	The minimum depth is the number of nodes along the shortest path from 
	the root node down to the nearest leaf node.
	*/
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		// 1e9 is an assuming upper bound of the depth of the tree, not safe
		int ans = 1e9;
		if (root->left != NULL)
			ans = min(ans, minDepth(root->left) + 1);
		if (root->right != NULL)
			ans = min(ans, minDepth(root->right) + 1);

		if (ans != 1e9)
			return ans;
		// if the node is a leaf node
		return 1;
	}
};

int main() {
	Solution s;
	
	TreeNode* root = new TreeNode(100);
	assert(s.minDepth(root) == 1);

	TreeNode*left = new TreeNode(233);
	TreeNode*right = new TreeNode(666);
	TreeNode* left_left_child = new TreeNode(555);

	root->setLeft(left);
	root->setRight(right);
	left->setLeft(left_left_child);

	assert(s.minDepth(root) == 2);

	return 0;
}
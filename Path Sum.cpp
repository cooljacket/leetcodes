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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		return sumHelper(root, sum);
	}

	bool sumHelper(TreeNode* root, int target) {
		if (root == NULL)
			return target == 0;

		if (root->left != NULL && sumHelper(root->left, target-root->val))
			return true;
			
		if (root->right != NULL && sumHelper(root->right, target-root->val))
			return true;

		// the leaf
		return root->left == NULL && root->right == NULL && target == root->val;
	}
};


int main() {
	Solution s;
	
	TreeNode* root = new TreeNode(5);
	assert(s.hasPathSum(root, 5) == true);
	assert(s.hasPathSum(root, 1) == false);

	TreeNode*left = new TreeNode(3);
	TreeNode*right = new TreeNode(7);
	TreeNode* left_left_child = new TreeNode(1);

	root->setLeft(left);
	root->setRight(right);
	left->setLeft(left_left_child);

	assert(s.hasPathSum(root, 8) == false);
	assert(s.hasPathSum(root, 9) == true);
	assert(s.hasPathSum(root, 12) == true);
	assert(s.hasPathSum(root, 10) == false);
	
	/*if (s.hasPathSum(root, 8))
		printf("yes\n");
	else
		printf("no\n");*/


	return 0;
}
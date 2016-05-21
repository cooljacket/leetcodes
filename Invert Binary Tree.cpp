#include <stdio.h>
#include <vector>
#include <string>
#include <map>
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
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		invertTree(root->left);
		invertTree(root->right);
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		return root;
	}
};


int main() {
	Solution s;

	TreeNode* root = new TreeNode(100);
	TreeNode*left = new TreeNode(233);
	TreeNode*right = new TreeNode(666);
	TreeNode* left_left_child = new TreeNode(555);

	root->setLeft(left);
	root->setRight(right);
	left->setLeft(left_left_child);

	s.invertTree(root);

	return 0;
}
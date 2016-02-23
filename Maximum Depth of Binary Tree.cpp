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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};


int main() {
	Solution s;

	TreeNode* root = new TreeNode(100);
	TreeNode*left = new TreeNode(233);
	TreeNode*right = new TreeNode(666);
	TreeNode* left_left_child = new TreeNode(555);

	assert(s.maxDepth(root) == 1);

	root->setLeft(left);
	assert(s.maxDepth(root) == 2);

	root->setRight(right);
	assert(s.maxDepth(root) == 2);

	left->setLeft(left_left_child);
	assert(s.maxDepth(root) == 3);


	return 0;
}
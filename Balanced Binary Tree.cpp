#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
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
	bool isBalanced(TreeNode* root) {
		return height(root) != -1;
	}

	// return -1 if the height is not satisfied with the definition of bt
	int height(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left = height(root->left);
		int right = height(root->right);

		printf("root->val=%d, left=%d, right=%d\n", root->val, left, right);

		if (left == -1 || right == -1 || left-right > 1 || right-left > 1)
			return -1;

		return max(left, right) + 1;
	}
};


int main() {
	Solution s;
	TreeNode* root = new TreeNode(5);

	assert(s.isBalanced(root) == true);
	printf("\n");

	root->setLeft(new TreeNode(3));
	root->left->setLeft(new TreeNode(1));
	assert(s.isBalanced(root) == false);
	printf("\n");

	root->setRight(new TreeNode(7));
	assert(s.isBalanced(root) == true);

	return 0;
}
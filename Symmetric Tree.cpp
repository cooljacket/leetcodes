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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		
		// recursive method
		return symmHelper(root->left, root->right);
	}

	bool symmHelper(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		if (p == NULL && q != NULL)
			return false;
		if (q == NULL && p != NULL)
			return false;

		return p->val == q->val && symmHelper(p->left, q->right) && symmHelper(p->right, q->left);
	}
};


int main() {
	Solution s;
	TreeNode* root = new TreeNode(5);

	assert(s.isSymmetric(root) == true);

	root->setLeft(new TreeNode(3));
	root->left->setLeft(new TreeNode(1));
	assert(s.isSymmetric(root) == false);

	root->setRight(new TreeNode(3));
	root->right->setRight(new TreeNode(1));
	assert(s.isSymmetric(root) == true);

	return 0;
}
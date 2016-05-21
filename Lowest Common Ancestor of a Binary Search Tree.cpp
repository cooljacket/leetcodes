#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return root;

		if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);

		if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);

		return root;		
	}
};


int main() {
	Solution s;


	return 0;
}
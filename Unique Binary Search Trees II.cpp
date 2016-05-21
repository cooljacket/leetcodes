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
	vector<TreeNode*> collections;
	int size;

	void helper(TreeNode* root, int num) {
		if (num > size) {
			collections.push_back(root);
		}
	}

	vector<TreeNode*> generateTrees(int n) {
		size = n;
		for (int i = 1; i <= n; ++i) {
			TreeNode* root = new TreeNode(i);
			helper(root, 1);
		}
		return collections;
	}
};
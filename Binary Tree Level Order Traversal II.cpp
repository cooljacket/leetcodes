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
	vector<vector<int> > levelOrderBottom(TreeNode* root) {
		vector<vector<int> > ans;
		if (root == NULL)
			return ans;

		queue<pair<TreeNode*, int> > q;
		q.push(make_pair(root, 0));

		while (!q.empty()) {
			int index = q.front().second;
			TreeNode* now = q.front().first;
			q.pop();
			if (now->left != NULL)
				q.push(make_pair(now->left, index+1));
			if (now->right != NULL)
				q.push(make_pair(now->right, index+1));

			while (ans.size() <= index)
				ans.push_back(vector<int>());
			ans[index].push_back(now->val);
		}

		/*for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans[i].size(); ++j)
				printf("%d ", ans[i][j]);
			printf("\n");
		}*/

		vector<vector<int> > res(ans.size());
		for (int i = 0, j = ans.size()-1; j >= 0; ++i, --j)
			res[i] = ans[j];

		return res;
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

	s.levelOrderBottom(root);

	return 0;
}
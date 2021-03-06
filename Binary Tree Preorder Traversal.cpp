#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
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
二叉树先序遍历
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		preorderTraversalHelper(root, v);
		return v;
	}

private:
	// 注意为什么在递归的开头判断是否为NULL，还在后面判断左右子结点是否为空
	// 是因为不想递归太深，能少一层是一层！
	void preorderTraversalHelper(TreeNode* root, vector<int>& v) {
		if (root == NULL)
			return ;
		v.push_back(root->val);
		if (root->left != NULL)
			preorderTraversalHelper(root->left, v);
		if (root->right != NULL)
			preorderTraversalHelper(root->right, v);
	}
};


int main() {
	TreeNode* root = new TreeNode(5);
	TreeNode* r_left = root->addLeftChild(3);
	TreeNode* r_left_left = r_left->addLeftChild(1);
	TreeNode* r_left_right = r_left->addRightChild(4);
	TreeNode* r_right = root->addRightChild(7);
	TreeNode* r_right_right = r_right->addRightChild(9);
	vector<int> res = Solution().preorderTraversal(root);
	display_v(res);


	return 0;
}
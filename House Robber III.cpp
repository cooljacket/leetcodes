#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
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
马贼所在的区域是一颗二叉树，根节点是入口，其余节点都是有人住的房子，如果同一条边上的两家人被偷，
就会触动报警，求马贼能够偷到的最大金额。
*/


class Solution {
public:
	/*思路：树形dp
	dp[father][0] = max(
		dp[leftChild][0] + dp[rightChild][0], 
		dp[leftChild][0] + dp[rightChild][1], 
		dp[leftChild][1] + dp[rightChild][0], 
		dp[leftChild][1] + dp[rightChild][1]
	);

	dp[father][1] = dp[leftChild][0] + dp[rightChild][0];*/

	int rob(TreeNode* root) {
		vector<int> dp(2, 0);
		robHelper(root, dp);
		return max(dp[0], dp[1]);
	}

private:
	void robHelper(TreeNode* root, vector<int>& dp) {
		if (root == NULL)
			return ;
		if (root->left == NULL && root->right == NULL) {
			dp[0] = 0;
			dp[1] = root->val;
			return ;
		}

		vector<int> left(2, 0);
		vector<int> right(2, 0);
		if (root->left != NULL) {
			robHelper(root->left, dp);
			left = dp;
		}
		if (root->right != NULL) {
			robHelper(root->right, dp);
			right = dp;
		}
		
		dp[0] = dp[1] = 0;
		dp[1] = left[0] + right[0] + root->val;
		dp[0] = max(dp[0], left[0] + right[0]);
		dp[0] = max(dp[0], left[0] + right[1]);
		dp[0] = max(dp[0], left[1] + right[0]);
		dp[0] = max(dp[0], left[1] + right[1]);
	}
};


int main() {
	TreeNode* root1 = new TreeNode(3);
	TreeNode* left1 = root1->addLeftChild(2);
	TreeNode* left_right1 = left1->addRightChild(3);

	TreeNode* right1 = root1->addRightChild(3);
	TreeNode* right_right1 = right1->addRightChild(1);
	cout << Solution().rob(root1) << endl;
	



	TreeNode* root2 = new TreeNode(3);
	TreeNode* left2 = root2->addLeftChild(4);
	TreeNode* left_left2 = left2->addLeftChild(1);
	TreeNode* left_right2 = left2->addRightChild(3);

	TreeNode* right2 = root2->addRightChild(5);
	TreeNode* right_right2 = right2->addRightChild(1);
	cout << Solution().rob(root2) << endl;

	return 0;
}
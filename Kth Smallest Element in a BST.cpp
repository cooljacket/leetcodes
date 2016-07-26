#include <iostream>
#include <stdio.h>
#include <cmath>
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
找出二叉查找树的第K个最小的元素

限制：
1. 尽量利用BST的性质；
2. 如果可以修改BST的节点的结构的话？
3. 优化过后的时间复杂度为O(BST的高度)
*/
class Solution {
public:
	// 思路：
	// 1）最笨的是：用中序遍历，把最小的K个输出出来;
	// 2）我想不到别的辣，哈哈
	// 3）不过如果可以给结点加一个以它为根的子树的结点数，那就会更快很多了！
	int kthSmallest(TreeNode* root, int k) {
		int key = 233, cnt = 0;
		findKSmallest(root, cnt, k, key);
		cout << k << ' ' << key << endl;
		return key;
	}

private:
	void findKSmallest(TreeNode* root, int& cnt, int k, int& it) {
		if (root == NULL)
			return ;
		if (root->left != NULL)
			findKSmallest(root->left, cnt, k, it);
		if (++cnt == k) {
			it = root->val;
			return ;
		}
		if (root->right != NULL)
			findKSmallest(root->right, cnt, k, it);
	}
};


int main() {
	TreeNode* root = new TreeNode(5);
	TreeNode* r_left = root->addLeftChild(3);
	TreeNode* r_left_left = r_left->addLeftChild(1);
	TreeNode* r_left_right = r_left->addRightChild(4);
	TreeNode* r_right = root->addRightChild(7);
	TreeNode* r_right_right = r_right->addRightChild(9);
	assert(Solution().kthSmallest(root, 3) == 4);
	assert(Solution().kthSmallest(root, 1) == 1);
	assert(Solution().kthSmallest(root, 4) == 5);
	assert(Solution().kthSmallest(root, 6) == 9);
	
	return 0;
}
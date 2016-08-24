#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
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
奇葩的问题，不敢苟同。。。

参考：https://www.hrwhisper.me/leetcode-linked-list-random-node/
*/
class Solution {
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		pHead = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode* now = pHead;
		int ans = now->val;
		for (int i = 1; now != NULL; ++i, now = now->next) {
			if (rand() % i == 0)
				ans = now->val;
		}
		return ans;
	}

private:
	ListNode *pHead;
};


int main() {
	

	return 0;
}
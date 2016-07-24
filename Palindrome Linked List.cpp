#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
用O(n)的时间和O(1)的空间，判断一个单链表是否是回文的
*/
class Solution {
public:
	// 思路：先把前一半的链表反转，从中间开始往两边走，边走边判断
	// 缺点：改变了链表的结构
	// solution：在判断的时候顺手把结构恢复
	bool isPalindrome(ListNode* head) {
		int len = getListLength(head);
		int halfSize = len >> 1, step = 0;
		ListNode *last = NULL;
		ListNode* rightHead = reverseList(head, last, halfSize);
		ListNode *leftHead = last;
		ListNode *leftHeadCopy = leftHead, *rightHeadCopy = rightHead;
		if (len % 2 != 0)
			rightHead = rightHead->next;

		bool ans = true;
		while (leftHead != NULL) {
			if (leftHead->val != rightHead->val) {
				ans = false;
				break;
			}
			leftHead = leftHead->next;
			rightHead = rightHead->next;
		}

		// 最后，恢复链表的结构
		reverseList(leftHeadCopy, rightHeadCopy, halfSize);

		return ans;
	}

	// 遍历链表，计算其长度
	int getListLength(ListNode* head) {
		int len = 0;
		while (head != NULL) {
			++len;
			head = head->next;
		}
		return len;
	}

	// 反转一段链表times步
	ListNode* reverseList(ListNode* head, ListNode*& last, int times) {
		ListNode *now = head, *tmp;
		int step = 0;
		while (step++ < times && now != NULL) {
			tmp = now->next;
			now->next = last;
			last = now;
			now = tmp;
		}
		return now;
	}
};


int main() {
	ListNode* head;
	head = genListSample(head, 5);
	head->display();
	Solution().isPalindrome(head);
	head->display();

	return 0;
}
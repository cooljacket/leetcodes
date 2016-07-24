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
1）将单链表相邻两个节点交换；
2）只能使用常数空间；
3）只能改变节点，不能只改变节点的值。
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		// 首先排除空链表和只有一个元素的链表的情况
		if (head == NULL || head->next == NULL)
			return head;

		// 头部的两个元素做特殊处理，交换相当于把头部插入到第二个节点后面而已
		// 所以before元素的值是head，而新的头部的值是原来的第二个节点
		ListNode *before = head, *newHead = head->next, *tmp;
		insertAfter(newHead, head);
		// 保证始终都有两个元素可以做交换，因为如果只剩下一个元素，就可以直接终止了
		// 在before->A->B->after模型里，交换前，before->next就是指A，before->next->next就是指B
		while (before->next != NULL && before->next->next != NULL) {
			// 这个交换动作其实可以等价抽象为：将第一个节点拿掉，插入到第二个节点后面！
			tmp = deleteAfter(before);
			insertAfter(before->next, tmp);
			before = tmp;
		}

		return newHead;
	}

	void insertAfter(ListNode *node, ListNode *toInsert) {
		toInsert->next = node->next;
		node->next = toInsert;
	}

	ListNode* deleteAfter(ListNode *node) {
		ListNode *toDelete = node->next;
		if (toDelete != NULL)
			node->next = toDelete->next;
		return toDelete;
	}
};


int main() {
	ListNode* head = NULL;
	head = genListSample(head, 5);
	head->display();
	head = Solution().swapPairs(head);
	head->display();

	return 0;
}
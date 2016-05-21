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


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}

	void append(int x) {
		assert(this != NULL);
		ListNode* now = this;
		while (now->next != NULL)
			now = now->next;
		now->next = new ListNode(x);
	}

	void print() {
		ListNode* now = this;
		while (now != NULL) {
			printf("%d ", now->val);
			now = now->next;
		}
		printf("\n");
	}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = len_of_list(headA), lenB = len_of_list(headB);
		if (lenA < lenB) {
			while (lenA < lenB) {
				headB = headB->next;
				--lenB;
			}
		} else if (lenB < lenA) {
			while (lenB < lenA) {
				headA = headA->next;
				--lenA;
			}
		}

		while (headA != headB && headA != NULL && headB != NULL) {
			headA = headA->next;
			headB = headB->next;
		}

		return headA;
	}

	int len_of_list(ListNode* head) {
		int len = 0;
		while (head != NULL) {
			++len;
			head = head->next;
		}
		return len;
	}
};


int main() {
	Solution s;
	
	ListNode* a = new ListNode(0);
	for (int i = 1; i < 6; ++i)
		a->append(i);
	a->print();

	ListNode* b = new ListNode(6);
	b->next = a->next->next;
	b->print();

	ListNode* c = s.getIntersectionNode(a, b);
	c->print();

	return 0;
}
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
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
	// assume the order is increasing
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		int x;
		if (l1->val < l2->val) {
			x = l1->val;
			l1 = l1->next;
		}
		else {
			x = l2->val;
			l2 = l2->next;
		}

		ListNode* head = new ListNode(x);
		ListNode* now = head;

		while (l1 != NULL || l2 != NULL) {
			if (l1 == NULL) {
				now->next = new ListNode(l2->val);
				l2 = l2->next;
			} else if (l2 == NULL) {
				now->next = new ListNode(l1->val);
				l1 = l1->next;
			} else {
				if (l1->val < l2->val) {
					now->next = new ListNode(l1->val);
					l1 = l1->next;
				}
				else {
					now->next = new ListNode(l2->val);
					l2 = l2->next;
				}
			}
			now = now->next;
		}

		now->next = NULL;

		return head;
	}
};


int main() {
	Solution s;

	ListNode* list1 = new ListNode(0);
	ListNode* list2 = new ListNode(1);

	for (int i = 0; i < 16; i+=2)
		list1->append(i);
	for (int i = 1; i < 16; i+=2)
		list2->append(i);

	list1->print();
	list2->print();

	ListNode* newList = s.mergeTwoLists(list1, list2);
	newList->print();

	return 0;
}
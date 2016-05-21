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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;

		int last = head->val;
		ListNode* now = head->next;
		ListNode* pre = head;
		while (now != NULL) {
			if (now->val != pre->val) {
				pre->next = now;
				pre = now;
			}

			now = now->next;
		}
		pre->next = NULL;

		return head;
	}
};

int main() {
	Solution s;

	// when list has only one element
	ListNode* list = new ListNode(0);
	list->print();
	s.deleteDuplicates(list);
	list->print();

	// when list has many elements
	for (int i = 1; i < 10; ++i)
		// list->append((i+1)/5);
		list->append(i);

	list->print();
	s.deleteDuplicates(list);
	list->print();	

	return 0;
}
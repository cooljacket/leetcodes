// https://leetcode.com/problemset/algorithms/
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
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
	void deleteNode(ListNode* node) {
		if (node->next == NULL)
			node = NULL;
		else {
			node->val = node->next->val;
			node->next = node->next->next;
		}
	}
};


int main() {
	Solution s;

	// when list has only one element
	ListNode* list = new ListNode(6);
	list->print();
	s.deleteNode(list);
	list->print();

	// when list has many elements
	for (int i = 1; i < 16; i+=2)
		list->append(i);

	ListNode* del = list->next;

	list->print();
	s.deleteNode(del);
	list->print();	

	return 0;
}
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
	ListNode* reverseList(ListNode* head) {
		ListNode *last = NULL, *now = head;

		while (now != NULL) {
			ListNode* tmp = now->next;
			now->next = last;
			last = now;
			now = tmp;
		}

		return last;
	}
};


int main() {
	Solution s;

	ListNode* list = new ListNode(0);
	for (int i = 1; i < 10; ++i)
		list->append(i);

	list->print();
	list = s.reverseList(list);
	list->print();

	return 0;
}
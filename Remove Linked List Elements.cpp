#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream>
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *prev = NULL, *now = head;

		while (now != NULL) {
			// Point: you should keep a copy of the next node because now may be deleted
			ListNode* nextOne = now->next;
			bool headGone = false;
			if (now->val == val)
				headGone = deleteNode(head, prev);
			else
				prev = now;
			if (headGone)
				prev = NULL;
			now = nextOne;
		}

		return head;
	}

	bool deleteNode(ListNode*& head, ListNode* prev) {
		if (prev == NULL) {
			ListNode* newHead = head->next;
			delete head;
			head = newHead;
			return true;
		}

		ListNode* nextOne = prev->next->next;
		delete prev->next;
		prev->next = nextOne;

		return false;
	}
};

int main() {
	Solution s;

	ListNode* head = new ListNode(1);
	for (int i = 2; i < 12; ++i)
		head->append(i/2);

	head->print();
	head = s.removeElements(head, 1);
	head->print();

	head = s.removeElements(head, 5);
	head->print();

	head = s.removeElements(head, 3);
	head->print();

	return 0;
}
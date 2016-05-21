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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int key = getLength(head) - n, index = 0;

		// if remove the head
		if (key == 0) {
			ListNode* newHead = head->next;
			delete head;
			return newHead;
		}


		// else
		ListNode* now = head;
		while (now != NULL && ++index < key)
			now = now->next;

		ListNode* nextOne = now->next->next;
		delete now->next;
		now->next = nextOne;

		return head;
	}

	int getLength(ListNode* head) {
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

	ListNode* head = new ListNode(1);
	for (int i = 2; i < 10; ++i)
		head->append(i);

	head->print();
	head = s.removeNthFromEnd(head, 1);
	head->print();


	head = s.removeNthFromEnd(head, 8);
	head->print();

	return 0;
}
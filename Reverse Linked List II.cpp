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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n)
			return head;

		ListNode *left = NULL, *right = NULL;
		ListNode *left_pre = NULL, *right_next = NULL;
		ListNode *now = head, *last = NULL;
		
		for (int i = 1; now != NULL; ++i) {
			if (i == m-1)
				left_pre = now;
			else if (i == m) 
				left = last = now;
			else if (i == n)
				right = now;
			else if (i > n) {
				right_next = now;
				break;
			}
			
			// case i in (m, n]
			if (i > m) {
				ListNode* nextOne = now->next;
				now->next = last;
				last = now;
				now = nextOne;
				continue;
			}

			now = now->next;
		}

		if (left_pre == NULL)
			head = left_pre = right;
		else
			left_pre->next = right;

		left->next = right_next;

		return head;
	}
};


int main() {
	Solution s;

	ListNode* head = new ListNode(1);
	for (int i = 2; i <= 10; ++i)
		head->append(i);

	printf("between 2 and 9:\n");
	head = s.reverseBetween(head, 2, 9);
	head->print();
	head = s.reverseBetween(head, 2, 9);
	head->print();

	printf("\ninclude the head:\n");
	head = s.reverseBetween(head, 1, 9);
	head->print();
	head = s.reverseBetween(head, 1, 9);
	head->print();

	printf("\nreverse the total list:\n");
	head = s.reverseBetween(head, 1, 10);
	head->print();
	head = s.reverseBetween(head, 1, 10);
	head->print();


	printf("\nreverse one element:\n");
	head = s.reverseBetween(head, 1, 1);
	head->print();
	head = s.reverseBetween(head, 1, 1);
	head->print();

	return 0;
}
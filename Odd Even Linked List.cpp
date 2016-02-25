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
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL)
			return head;

		vector<ListNode*> odd, even;
		int index = 0;
		ListNode* now = head;
		while (now != NULL) {
			if (++index % 2 == 1)
				odd.push_back(now);
			else
				even.push_back(now);
			now = now->next;
		}

		now = append(odd, head);
		if (!even.empty()) {
			now->next = even[0];
			now = append(even, even[0]);
		}
		now->next = NULL;

		return head;
	}

	ListNode* append(const vector<ListNode*>& v, ListNode* head) {
		ListNode* now = head;
		for (int i = 1; i < v.size(); ++i) {
			now->next = v[i];
			now = v[i];
		}

		return now;
	}
};


int main() {
	Solution s;

	// when list has only one element
	ListNode* list = new ListNode(1);
	list->print();
	s.oddEvenList(list);
	list->print();

	// when list has many elements
	for (int i = 2; i < 10; ++i)
		list->append(i);

	list->print();
	s.oddEvenList(list);
	list->print();	

	return 0;
}
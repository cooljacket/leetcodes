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
问题分析：判断给定的单链表是否有环
*/
class Solution {
public:
	// 思路：经典的”快慢指针“
	bool hasCycle(ListNode *head) {
		ListNode *one = head, *two = head;
		while (two != NULL) {
			one = one->next;
			two = two->next;
			if (two == NULL)
				return false;
			two = two->next;
			if (one == two)
				return true;
		}
		return false;
	}
};


int main() {
	ListNode *head = new ListNode(1);
	ListNode *n1 = head->append(2);
	ListNode *n2 = n1->append(3);
	ListNode *n3 = n2->append(4);
	ListNode *n4 = n3->append(5);
	bool have = Solution().hasCycle(head);
	cout << (have ? "have cycle" : "no cycle") << endl;

	n4->setNext(n2);
	have = Solution().hasCycle(head);
	cout << (have ? "have cycle" : "no cycle") << endl;

	return 0;
}
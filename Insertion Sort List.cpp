#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
#include "headers/TreeNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;
typedef TreeNodeTemplate<int> TreeNode;


/*
问题要求：
在单链表上做插入排序
*/
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode *last = NULL, *now = head, *next;
		while (now != NULL) {
			next = now->next;
			ListNode *tmp = last, *tmpLast = NULL;
			while (tmp != NULL && now->val < tmp->val) {
				tmpLast = tmp;
				tmp = tmp->next;
			}
			now->next = tmp;
			if (tmpLast != NULL) {
				tmpLast->next = now;
			}
			else {
				last = now;
			}
			now = next;
		}
		return reverseList(last);
	}

private:
	ListNode* reverseList(ListNode* pHead) {
		ListNode *last = NULL, *now = pHead, *next;
		while (now != NULL) {
			next = now->next;
			now->next = last;
			last = now;
			now = next;
		}
		return last;
	}
};
// 也可以直接正向来做
// class Solution {
// public:
// 	ListNode* insertionSortList(ListNode* head) {
// 		ListNode *newHead = NULL, *now = head, *next, *tmp, *tmpLast;
// 		while (now != NULL) {
// 			next = now->next;
// 			tmp = newHead;
// 			tmpLast = NULL;
// 			while (tmp != NULL && now->val > tmp->val) {
// 				tmpLast = tmp;
// 				tmp = tmp->next;
// 			}
// 			if (tmpLast != NULL) {
// 				tmpLast->next = now;
// 				now->next = tmp;
// 			} else {
// 				now->next = tmp;
// 				newHead = now;
// 			}
// 			now = next;
// 		}
// 		return newHead;
// 	}
// };



int main() {
	int arr1[] = {3, 4, 1};
	ListNode* head = arr2List(arr1, 3);
	head->display();
	head = Solution().insertionSortList(head);
	head->display();

	return 0;
}
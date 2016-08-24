#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
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
实现LRU缓存
*/
class LRUCache{
public:
	// 注意自己维护list的size就好了，标准库的list的size()方法是O(n)时间的。。。
	LRUCache(int capacity)
	: size(0), capacity(capacity) {}

	int get(int key) {
		Node* node = findAndUpdate(key);
		if (node == NULL)
			return -1;

		return node->value;
	}

	void set(int key, int value) {
		Node* node = findAndUpdate(key);
		if (node == NULL) {
			cache.push_back(new Node(key, value));
			if (++size > capacity) {
				--size;
				delete *(cache.begin());	// 注意回收内存！
				cache.pop_front();	
			}
		} else {
			node->value = value;
		}
	}

private:
	int size, capacity;

	struct Node {
		int key, value;
		Node(int k, int v)
		: key(k), value(v) {}
	};

	list<Node*> cache;

	Node* findAndUpdate(int key) {
		Node* goal = NULL;
		list<Node*>::iterator it = cache.begin();
		while (it != cache.end()) {
			if ((*it)->key == key) {
				goal = *it;
				cache.erase(it);
				cache.push_back(goal);
				break;
			}
			++it;
		}
		return goal;
	}
};


int main() {
	
	return 0;
}
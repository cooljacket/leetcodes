#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
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
实现LRU缓存算法
*/
class LRUCache{
public:
	// 注意自己维护list的size就好了，标准库的list的size()方法是O(n)时间的。。。
	// 还有，一开始我根据一个key在列表里线性查找，发现超时了
	// 所以就用了哈希表来根据key查找其在list中的位置
	// unordered_map用g++编译需要加选项-std=c++11
	LRUCache(int capacity)
	: m_size(0), m_capacity(capacity) {}

	int get(int key) {
		Node* node = findAndUpdate(key);
		if (node == NULL)
			return -1;
		return node->value;
	}

	void set(int key, int value) {
		Node* node = findAndUpdate(key);
		if (node == NULL) {
			insertNodeIntoCache(new Node(key, value));
			if (m_size > m_capacity)
				removeOldestFromCache();
		} else
			node->value = value;
	}

private:
	int m_size, m_capacity;

	struct Node {
		int key, value;
		Node(int k, int v)
		: key(k), value(v) {}
	};

	list<Node*> m_cache;
	typedef unordered_map<int, list<Node*>::iterator> Hash;
	Hash m_hashMap;

	Node* findAndUpdate(int key) {
		Hash::const_iterator it = m_hashMap.find(key);
		if (it == m_hashMap.end())
			return NULL;
		Node* goal = *(it->second);
		eraseFromList(it->second);
		insertNodeIntoCache(goal);
		return goal;
	}

	void eraseFromList(list<Node*>::iterator it) {
		Node* node = *it;
		m_hashMap.erase((*it)->key);
		m_cache.erase(it);
		--m_size;
	}

	void insertNodeIntoCache(Node* node) {
		m_cache.push_front(node);
		m_hashMap[node->key] = m_cache.begin();
		++m_size;
	}

	void removeOldestFromCache() {
		m_hashMap.erase(m_cache.back()->key);
		delete m_cache.back();
		m_cache.pop_back();
		--m_size;
	}
};


int main() {
	LRUCache LRU(1);
	LRU.set(2, 1);
	cout << LRU.get(2) << endl;
	LRU.set(3, 2);
	cout << LRU.get(2) << endl;
	cout << LRU.get(3) << endl;
	
	return 0;
}
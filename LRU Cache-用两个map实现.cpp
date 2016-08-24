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
实现LRU缓存
*/
class LRUCache{
public:
	// 用list会超时，改用map
	LRUCache(int capacity)
	: size(0), capacity(capacity), timestamp(0) {}

	int get(int key) {
		Node* node = findAndErase(key);
		if (node == NULL)
			return -1;
		// cout << "before... " << node->key << ' ' << node->value << endl;
		addNewElement(node);
		// cout << "geting... " << node->key << ' ' << node->value << endl;
		return node->value;
	}

	void set(int key, int value) {
		Node* node = findAndErase(key);
		if (node != NULL)
			delete node;
		addNewElement(new Node(key, value));
	}

private:
	int size, capacity, timestamp;

	struct Node {
		int key, value;
		Node(int k, int v)
		: key(k), value(v) {}
	};

	map<int, Node*> cache;
	map<int, int> key2time;

	Node* findAndErase(int key) {
		map<int, int>::iterator kit = key2time.find(key);
		if (kit == key2time.end())
			return NULL;
		map<int, Node*>::iterator cit = cache.find(kit->second);
		Node* goal = cit->second;
		// 擦除旧的记录
		cache.erase(cit);
		key2time.erase(kit);
		--size;
		// cout << "finding " << goal->key << ' ' << goal->value << endl;
		return goal;
	}

	void addNewElement(Node* node) {
		cache[++timestamp] = node;
		key2time[node->key] = timestamp;
		if (++size > capacity)
			eraseOldest();
		// cout << "adding " << node->key << ' ' << node->value << endl;
	}

	void eraseOldest() {
		map<int, Node*>::iterator oldest_it = cache.begin();
		int oldest_timestamp = oldest_it->first;
		Node* oldest_node = oldest_it->second;
		int oldest_key = oldest_node->key;
		cache.erase(oldest_it);
		key2time.erase(oldest_key);
		delete oldest_node;		// 注意回收内存！
		--size;
	}
};


int main() {
	LRUCache LRU(1);
	LRU.set(2, 1);
	cout << LRU.get(2) << endl;
	
	return 0;
}
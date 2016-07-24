#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
设计一个“最小栈”，使得这个栈的push, pop, top和获取栈里的最小值的操作都是O(1)时间的
*/
class MinStack {
public:
	// 其实很简单，用多一个栈来记录最小值就好了
	MinStack() {}

	void push(int x) {
		elements.push(x);
		if (minE.empty())
			minE.push(x);
		else
			minE.push(min(minE.top(), x));
	}

	void pop() {
		elements.pop();
		minE.pop();
	}

	int top() {
		return elements.top();
	}

	int getMin() {
		return minE.top();
	}

private:
	stack<int> elements, minE;
};


int main() {
	MinStack obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	cout << "top is " << obj.top() << endl;
	cout << "min is " << obj.getMin() << endl;

	return 0;
}
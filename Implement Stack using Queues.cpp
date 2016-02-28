#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;


class Stack {
public:
	queue<int> data;

	// Push element x onto stack.
	void push(int x) {
		data.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		queue<int> aux;
		while (data.size() > 1) {
			aux.push(data.front());
			data.pop();
		}
		data = aux;
	}

	// Get the top element.
	int top() {
		return data.back();
	}

	// Return whether the stack is empty.
	bool empty() {
		return data.empty();
	}


	void print() {
		queue<int> aux;
		while (!data.empty()) {
			aux.push(data.front());
			printf("%d ", data.front());
			data.pop();
		}
		data = aux;
		printf("\n\n");
	}
};

int main() {
	Stack s;
	
	for (int i = 0; i < 8; ++i)
		s.push(i);
	s.print();

	s.pop();
	s.print();
	printf("top=%d\n", s.top());

	return 0;
}
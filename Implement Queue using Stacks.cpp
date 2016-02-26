#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <assert.h>
using namespace std;


class Queue {
public:
	stack<int> data, aux;
	int front;

	// Push element x to the back of queue.
	void push(int x) {
		if (data.empty())
			front = x;
		data.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!data.empty()) {
			data_to_aux();
			aux.pop();
			if (!aux.empty())
				front = aux.top();
			aux_to_data();
		}
	}

	// Get the front element.
	int peek(void) {
		if (!data.empty())
			return front;

		// here can be handled as an exception~
		return -1;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return data.empty();
	}

	void data_to_aux() {
		while (!data.empty()) {
			aux.push(data.top());
			data.pop();
		}
	}

	void aux_to_data() {
		while (!aux.empty()) {
			data.push(aux.top());
			aux.pop();
		}
	}

	void print() {
		data_to_aux();
		stack<int> tmp = aux;
		aux_to_data();

		while (!tmp.empty()) {
			printf("%d ", tmp.top());
			tmp.pop();
		}
		printf("\n");
	}
};


int main() {
	Queue q;

	for (int i = 0; i < 10; ++i)
		q.push(i);
	q.print();

	printf("peek=%d\n", q.peek());

	q.pop();
	q.print();
	q.pop();
	q.print();

	return 0;
}
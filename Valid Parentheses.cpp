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
#include <cmath>
using namespace std;


class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); ++i) {
			if (isRight(s[i])) {
				if (st.empty())
					return false;
				if (checkMap(st.top(), s[i]))
					st.pop();
				else
					return false;
			} else if (isLeft(s[i]))
				st.push(s[i]);
			else
				return false;
		}

		return st.empty();
	}

	bool checkMap(char left, char right) {
		if (!isLeft(left) || !isRight(right))
			return false;
		if (left == '(' && right == ')')
			return true;
		if (left == '[' && right == ']')
			return true;
		if (left == '{' && right == '}')
			return true;
		return false;
	}

	bool isLeft(char c) {
		return c == '(' || c == '[' || c == '{';
	}

	bool isRight(char c) {
		return c == ')' || c == ']' || c == '}';
	}
};


int main() {
	Solution s;

	assert(s.isValid("") == true);
	assert(s.isValid("(") == false);
	assert(s.isValid("()") == true);
	assert(s.isValid("[]") == true);
	assert(s.isValid("{}") == true);
	assert(s.isValid("(]") == false);
	assert(s.isValid("(]([)]") == false);

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：

*/
class Solution {
public:
	int myAtoi(string str) {
		const int INT_MAX_ = 0x7fffffff, INT_MIN_ = 0x80000000;
		strip(str);
		if (str.empty())
			return 0;
		stringstream ss(str);
		double ans;
		ss >> ans;
		if (ans > INT_MAX_)
			ans = INT_MAX_;
		else if (ans < INT_MIN_)
			ans = INT_MIN_;
		// cout << "haha " << (int)ans << ' ' << INT_MAX_ << ' ' << INT_MIN_ << endl;
		return (int)ans;
	}

private:
	void strip(string& str) {
		int len = str.size(), left = 0, right;
		while (left < len && !isnum(str[left]))
			++left;
		right = left;
		while (right < len && isnum(str[right]))
			++right;
		str = str.substr(left, right - left);
	}

	bool isnum(char ch) {
		return (ch >= '0' && ch <= '9') || (ch == '+') || (ch == '-');
	}
};


int main() {
	assert(Solution().myAtoi("   ") == 0);
	assert(Solution().myAtoi("") == 0);
	assert(Solution().myAtoi(" -123 ") == -123);
	assert(Solution().myAtoi(" 233 ") == 233);
	assert(Solution().myAtoi("+666 ") == 666);
	assert(Solution().myAtoi(" b11228552307") == 2147483647);
	assert(Solution().myAtoi("   -115579378e25") == -115579378);
	return 0;
}
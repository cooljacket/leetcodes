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
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
class Solution {
public:
	int myAtoi(string str) {
		bool isNeg = strip(str);
		return str.empty() ? 0 : str2int(str, isNeg);
	}

private:
	bool strip(string& str) {
		int len = str.size(), left = 0, right;
		// 前缀只允许空格，其它非法字符则表示该字符串非法，应返回0
		while (left < len && !isNum(str[left]) && !isSign(str[left])) {
			if (str[left] != ' ') {
				str = "";
				return false;
			}
			++left;
		}

		// 处理正负号
		bool isNeg = false;
		if (isSign(str[left])) {
			isNeg = str[left] == '-';
			++left;
		}

		// 后缀的非法字符全部不用管，只看数字就好了
		right = left;
		while (right < len && isNum(str[right]))
			++right;

		str = str.substr(left, right - left);
		return isNeg;
	}

	bool isNum(char ch) {
		return (ch >= '0' && ch <= '9');
	}

	bool isSign(char ch) {
		return (ch == '+') || (ch == '-');
	}

	int str2int(const string& str, bool isNeg) {
		long long num = 0;
		for (int i = 0; i < str.size(); ++i) {
			num *= 10;
			num += (int)(str[i] - '0');
			if (!isNeg && num > INT_MAX_VALUE) {
				return INT_MAX_VALUE;
			} else if (isNeg && -num < INT_MIN_VALUE) {
				return INT_MIN_VALUE;
			}
		}
		return isNeg ? -num : num;

		// double num;
		// stringstream ss(str);
		// ss >> num;
		// if (isNeg)
		// 	num = -num;
		// if (num > INT_MAX_VALUE)
		// 	return INT_MAX_VALUE;
		// if (num < INT_MIN_VALUE)
		// 	return INT_MIN_VALUE;
		// return num;
	}

	static const int INT_MAX_VALUE = 0x7fffffff, INT_MIN_VALUE = 0x80000000;
};


int main() {
	assert(Solution().myAtoi("   ") == 0);
	assert(Solution().myAtoi("+-2") == 0);
	assert(Solution().myAtoi(" -123 ") == -123);
	assert(Solution().myAtoi(" 233 ") == 233);
	assert(Solution().myAtoi("+666 ") == 666);
	assert(Solution().myAtoi(" b11228552307") == 0);
	assert(Solution().myAtoi("   -115579378e25") == -115579378);
	return 0;
}
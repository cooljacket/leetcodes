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


class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		long long y = 0, xx = x, copy = x;
		while (xx > 0) {
			y *= 10;
			y += xx % 10;
			xx /= 10;
		}

		// printf("xx=%lld, y=%lld\n", copy, y);
		return y == copy;
	}
};


int main() {
	Solution s;
	
	assert(s.isPalindrome(2332) == true);
	assert(s.isPalindrome(123) == false);
	assert(s.isPalindrome(-1) == false);
	assert(s.isPalindrome(0) == true);
	assert(s.isPalindrome(-2147483648) == false);
	assert(s.isPalindrome(-2147447412) == false);
	assert(s.isPalindrome(2147447412) == true);


	return 0;
}
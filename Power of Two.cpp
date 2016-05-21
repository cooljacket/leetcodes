#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
using namespace std;


class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 0)
			return false;

		while (n % 2 == 0)
			n /= 2;

		return n == 1;
	}
};


int main() {
	Solution s;

	assert(s.isPowerOfTwo(0) == false);
	assert(s.isPowerOfTwo(1) == true);
	assert(s.isPowerOfTwo(2) == true);
	assert(s.isPowerOfTwo(8) == true);
	assert(s.isPowerOfTwo(15) == false);
	assert(s.isPowerOfTwo(1024) == true);


	return 0;
}
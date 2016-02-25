#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n == 0)
			return false;

		while (n % 3 == 0)
			n /= 3;

		return n == 1;
	}
};


int main() {
	Solution s;

	assert(s.isPowerOfThree(0) == false);
	assert(s.isPowerOfThree(1) == true);
	assert(s.isPowerOfThree(3) == true);
	assert(s.isPowerOfThree(27) == true);
	assert(s.isPowerOfThree(36) == false);
	assert(s.isPowerOfThree(81) == true);


	return 0;
}
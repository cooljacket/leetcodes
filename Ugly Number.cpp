#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
using namespace std;


class Solution {
public:
	bool isUgly(int num) {
		// zero has infinite factors, while negative integers always has a factor -1
		if (num <= 0)
			return false;

		int factors[] = {2, 3, 5};
		for (int i = 0; i < 3; ++i)
			if (num % factors[i] == 0) {
				while (num % factors[i] == 0)
					num /= factors[i];
			}

		return num == 1;
	}
};

int main() {
	Solution s;

	s.isUgly(905391974);
	assert(s.isUgly(1) == true);
	assert(s.isUgly(2) == true);
	assert(s.isUgly(3) == true);
	assert(s.isUgly(5) == true);

	assert(s.isUgly(14) == false);
	assert(s.isUgly(6) == true);
	assert(s.isUgly(8) == true);
	assert(s.isUgly(-2147483648) == false);

	return 0;
}
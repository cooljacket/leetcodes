#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <assert.h>
using namespace std;


class Solution {
public:
	int addDigits(int num) {
		int key = num % 9;
		if (num != 0 && key == 0)
			return 9;
		else
			return key;
	}
};


int main() {
	Solution s;
	for (int i = 0; i < 10; ++i) {
		printf("i=%d\n", i);
		assert(s.addDigits(i) == i);
	}

	assert(s.addDigits(38) == 2);

	return 0;
}
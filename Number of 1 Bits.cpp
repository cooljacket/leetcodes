#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
using namespace std;

typedef unsigned int uint32_t;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		for (int i = 0; i < 32; ++i) {
			if ((n & (1u << i)) != 0)
				++cnt;
			// printf("i=%d, x=%u, you=%u\n", i, (n & (1u << i)), (1u << i));
		}

		// printf("n=%u, cnt=%d\n", n, cnt);
		return cnt;
	}
};


int main() {
	Solution s;
	assert(s.hammingWeight(3u) == 2);
	assert(s.hammingWeight(8) == 1);
	assert(s.hammingWeight(0) == 0);
	assert(s.hammingWeight(1) == 1);
	assert(s.hammingWeight(7) == 3);
	assert(s.hammingWeight(2147483648u) == 1);

	return 0;
}
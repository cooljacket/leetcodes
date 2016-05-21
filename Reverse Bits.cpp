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
using namespace std;

typedef unsigned int uint32_t;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0, mask = 1u;
		for (int i = 0; i < 32; ++i) {
			ans = ans << 1;
			if ((n & mask) != 0)
				ans |= 1u;
			mask = mask << 1;
		}

		return ans;
	}
};


int main() {
	Solution s;

	assert(s.reverseBits(0u) == 0u);
	assert(s.reverseBits(1u) == 2147483648u);
	assert(s.reverseBits(43261596u) == 964176192u);

	return 0;
}
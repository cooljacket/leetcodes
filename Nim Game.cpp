#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <assert.h>
using namespace std;


class Solution {
public:
	bool canWinNim(int n) {
		return n % 4 != 0;
	}
};


int main() {
	Solution s;
	assert(s.canWinNim(1) == true);
	assert(s.canWinNim(2) == true);
	assert(s.canWinNim(3) == true);
	assert(s.canWinNim(4) == false);

	assert(s.canWinNim(7) == true);
	assert(s.canWinNim(8) == false);
	assert(s.canWinNim(666) == true);
	assert(s.canWinNim(233) == true);

	return 0;
}
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
	int trailingZeroes(int n) {
		int cnt = 0;
		while (n > 0) {
			n /= 5;
			cnt += n;
		}

		return cnt;
	}
};

int calZeros(int n) {
	long long ans = 1;
	for (int i = 2; i <= n; ++i)
		ans *= i;

	// printf("caling: %lld\n", ans);
	int num = 0;
	while (ans % 10 == 0) {
		++num;
		ans /= 10;
	}

	return num;
}

int main() {
	Solution s;
		
	assert(s.trailingZeroes(6) == calZeros(6));
	assert(s.trailingZeroes(10) == calZeros(10));
	assert(s.trailingZeroes(19) == calZeros(19));
	assert(s.trailingZeroes(13) == calZeros(13));
	assert(s.trailingZeroes(30) == 7);
	assert(s.trailingZeroes(50) == 12);
	assert(s.trailingZeroes(200) == 49);
	/*for (int i = 0; i < 5; ++i)
		assert(s.trailingZeroes(i) == 0);
*/
	for (int i = 0; i < 5; ++i)
		s.trailingZeroes(i);

	return 0;
}
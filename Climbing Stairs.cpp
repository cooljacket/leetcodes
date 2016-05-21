#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1 || n == 2)
			return n;
		vector<int> dp(n+1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i)
			dp[i] = dp[i-1] + dp[i-2];
		return dp[n];
	}
};


int main() {
	Solution s;

	assert(s.climbStairs(1) == 1);
	assert(s.climbStairs(2) == 2);
	assert(s.climbStairs(4) == 5);

	return 0;
}
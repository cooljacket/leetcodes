// https://leetcode.com/problems/perfect-squares/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		const int INF = 1e9;
		vector<int> dp(n+1, INF);
		int end = 1;
		while (end*end < n)
			++end;

		dp[0] = 0;
		for (int i = 1; i <= end; ++i) {
			int base = i*i;
			for (int j = n; j >= 1; --j)
				if (j >= base) {
					dp[j] = min(dp[j], dp[j-base]+1);
					printf("i=%d, j=%d, dp=%d\n", i, j, dp[j]);
				}
		}
		return dp[n];
	}
};

int main() {
	Solution s;
	cout << s.numSquares(2) << endl;
	// cout << s.numSquares(12) << endl;
	// cout << s.numSquares(13) << endl;
	return 0;
}
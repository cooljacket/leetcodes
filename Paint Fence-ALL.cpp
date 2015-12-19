// Leetcode: Paint Fence
// Ref: http://segmentfault.com/a/1190000003790650
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        // dp[3] = (k - 1) * (dp[1] + dp[2]);
        if (n == 1)
            return k;
        if (n == 2)
            return k*k;
        vector<vector<int> > dp(n+1, vector<int>(2, 0));
        dp[1][0] = k;
        dp[1][1] = 0;
        dp[2][0] = k*(k-1);
        dp[2][1] = k;
        for (int i = 3; i <= n; ++i) {
            dp[i][1] = dp[i-1][0];
            dp[i][0] = (k-1) * (dp[i-1][0] + dp[i-1][1]);
        }
        return dp[n][0] + dp[n][1];
    }

    int numWays2(int n, int k) {
        // 当n=0时返回0
        int dp[] = {0, k , k*k, 0};
        if(n <= 2){
            return dp[n];
        }
        for(int i = 2; i < n; i++){
            // 递推式：第三根柱子要么根第一个柱子不是一个颜色，要么跟第二根柱子不是一个颜色
            dp[3] = (k - 1) * (dp[1] + dp[2]);
            dp[1] = dp[2];
            dp[2] = dp[3];
        }
        return dp[3];
    }
};

// 测试证明自己的思路起码是跟这个已经解决了的人的结果是一致的
int main() {
    Solution sol;

    for (int n = 1; n <= 100; ++n)
        for (int k = 1; k <= 500; ++k)
            if (sol.numWays(n, k) != sol.numWays2(n, k))
                printf("wrong at: %d, %d\n", n, k);
    // for (int n = 1; n <= 10; ++n)
    //     for (int k = 1; k <= 5; ++k)
    //         printf("n=%d, k=%d, dp=%d\n", n, k, sol.numWays(n, k));

    return 0;
}
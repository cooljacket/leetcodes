// https://leetcode.com/problems/decode-ways/
// 挺多细节需要处理的,比如:
// 1) 有不能匹配的0,总的就是0,空串也是0;
// 2) 剩下的就是1x和2x之间要区别开来对待啦
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		int size = s.size();
		vector<int> dp(size+1, 0);
		if (s[0] != '0')
			dp[0] = dp[1] = 1;
		for (int i = 1; i < size; ++i)
			if ( (s[i-1] == '1') || (s[i-1] == '2' && s[i] <= '6') ) {
				if (s[i] > '0')
					dp[i+1] = dp[i] + dp[i-1];
				else
					dp[i+1] = dp[i-1];
			}
			else if (s[i] != '0')
				dp[i+1] = dp[i];
			else
				return 0;

		return dp[size];
	}
};

int main() {
	string s;
	cin >> s;
	Solution so;
	cout << so.numDecodings(s) << endl;
	return 0;
}
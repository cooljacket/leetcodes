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
#include <cmath>
#include <sstream>
using namespace std;


class Solution {
public:
	string countAndSay(int n) {
		string ans = "1";

		for (int i = 2; i <= n; ++i) {
			ans = sayItOut(ans);
			// printf("i=%d, ans=%s\n", i, ans.data());
		}

		return ans;
	}

	string sayItOut(const string& s) {
		char last = s[0], now = s[0];
		int size = s.size(), count = 1;
		string ans;

		for (int i = 1; i < size; ++i) {
			now = s[i];
			if (now != last) {
				ans += toString(count, last);
				count = 1;
			}
			else
				++count;
			last = now;
		}

		ans += toString(count, now);

		return ans;
	}

	string toString(int count, char ch) {
		stringstream ss;
		ss << count << ch;
		return ss.str();
	}
};


int main() {
	Solution s;

	// assert(s.countAndSay(1) == "1");
	assert(s.countAndSay(2) == "11");
	assert(s.countAndSay(3) == "21");
	assert(s.countAndSay(4) == "1211");
	assert(s.countAndSay(5) == "111221");

	return 0;
}
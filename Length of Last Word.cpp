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
using namespace std;


class Solution {
public:
	int lengthOfLastWord(string s) {
		int ans = 0, len = s.size(), word_len = 0;
		for (int i = 0; i < len; ++i) {
			if (s[i] == ' ') {
				if (word_len != 0)
					ans = word_len;
				word_len = 0;
			}
			else {
				++word_len;
				if (i == len-1)
					return word_len;
			}
		}

		return ans;
	}
};


int main() {
	Solution s;

	assert(s.lengthOfLastWord("") == 0);
	assert(s.lengthOfLastWord("  ") == 0);
	assert(s.lengthOfLastWord("abc") == 3);
	assert(s.lengthOfLastWord("hello jacket") == 6);
	assert(s.lengthOfLastWord("hello jacket    ") == 6);
	assert(s.lengthOfLastWord("Today is a good day") == 3);

	return 0;
}
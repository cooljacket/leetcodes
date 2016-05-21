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
	// need in-place and O(1) space to solve
	void reverseWords(string& s) {
		// first, you should get enough space to reverse each word
		// but notice that each word is exactly equal to itself in size!!!!!!
		// this is the most important property to solve this problem in O(1) space
		if (s.empty() || s == " ") {
			s = "";
			return;
		}

		int start = -1, len = s.size();
		reverseHelper(s, 0, len-1);

		for (int i = 0; i < len; ++i) {
			if (start == -1 && s[i] != ' ')
				start = i;
			else if (start != -1 && (s[i] == ' ' || i == len-1)) {
				int tail = i - 1;
				if (i == len-1 && s[i] != ' ')
					tail = i;
				reverseHelper(s, start, tail);
				// printf("i=%d, s=%s, start=%d, tail=%d\n", i, s.data(), start, tail);
				start = -1;
			}
		}
	}

	void reverseHelper(string& s, int beg, int end) {
		for (int i = beg, j = end; i < j; ++i, --j)
			swap(s[i], s[j]);
	}
};


int main() {
	Solution s;

	string str("hello jacket");
	printf("Original str=%s\n", str.data());
	s.reverseWords(str);
	printf("After reversing, str=%s\n", str.data());

	return 0;
}
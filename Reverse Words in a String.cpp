#include <stdio.h>
#include <iostream>
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
		// 首先要处理多余的空格，将其缩减为一个
		int last_nws = -2, len = s.size();
		for (int i = 0; i < len; ++i) {
			if (s[i] != ' ') {
				if (i - last_nws > 2) {
					while (i < len && s[i] != ' ')
						swap(s[(++last_nws)+1], s[i++]);
					++last_nws;
				} else
					last_nws = i;
			}
		}
		if (last_nws == -2)
			last_nws = -1;
		s = s.substr(0, last_nws+1);
		if (s.empty())
			return;

		int start = -1;
		len = s.size();
		reverseHelper(s, 0, len-1);

		for (int i = 0; i < len; ++i) {
			if (start == -1 && s[i] != ' ')
				start = i;
			else if (start != -1 && (s[i] == ' ' || i == len-1)) {
				int tail = i - 1;
				if (i == len-1 && s[i] != ' ')
					tail = i;
				reverseHelper(s, start, tail);
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

	string str1("ab         c   d  ");
	s.reverseWords(str1);
	cout << str1 << endl << endl;;

	string str2(" ab  c   d ");
	s.reverseWords(str2);
	cout << str2 << endl << endl;;

	string str3(" ab  c   d");
	s.reverseWords(str3);
	cout << str3 << endl << endl;;

	string str4("ab c   d");
	s.reverseWords(str4);
	cout << str4 << endl << endl;;

	string str5(" ");
	s.reverseWords(str5);
	cout << str5 << "xxxx" << endl << endl;;

	string str6("  the     sky    is blue  ");
	s.reverseWords(str6);
	cout << str6 << endl << endl;;

	return 0;
}
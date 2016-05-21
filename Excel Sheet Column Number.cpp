#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <assert.h>
using namespace std;


class Solution {
public:
	int titleToNumber(string s) {
		int num = 0, base = 1;
		for (int i = s.size()-1; i >= 0; --i) {
			num += toInt(s[i]) * base;
			base *= 26;
		}

		return num;
	}

	int toInt(char c) {
		return c - 'A' + 1;
	}
};


int main() {
	Solution s;

	string sc = "A";
	for (char c = 'A'; c <= 'Z'; ++c) {
		sc[0] = c;
		assert(s.titleToNumber(sc) == c-'A'+1);
	}

	assert(s.titleToNumber("AA") == 27);
	assert(s.titleToNumber("AB") == 28);

	return 0;
}
// refer: https://en.wikipedia.org/wiki/Roman_numerals
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <assert.h>
using namespace std;


class Solution {
public:
	map<char, int> getValue;
	Solution() {
		char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
		int values[] = {1, 5, 10, 50, 100, 500, 1000};
		int size = sizeof(values) / sizeof(int);
		for (int i = 0; i < size; ++i)
			getValue[symbols[i]] = values[i];
	}
	
	int romanToInt(string s) {
		int num = 0, last = 2000;
		for (int i = 0; i < s.size(); ++i) {
			int value = getValue[s[i]];
			if (value <= last)
				num += value;
			else
				num += value - 2*last;
			last = value;
		}

		return num;
	}
};


int main() {
	Solution s;
	assert(s.romanToInt("I") == 1);
	assert(s.romanToInt("V") == 5);
	assert(s.romanToInt("X") == 10);
	assert(s.romanToInt("L") == 50);
	assert(s.romanToInt("C") == 100);
	assert(s.romanToInt("D") == 500);
	assert(s.romanToInt("M") == 1000);

	assert(s.romanToInt("MCMLIV") == 1954);
	assert(s.romanToInt("MCMXC") == 1990);
	assert(s.romanToInt("MMXVI") == 2016);

	return 0;
}
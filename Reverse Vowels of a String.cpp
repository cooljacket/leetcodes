#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;



/*
问题分析：忽略不是元音字母的字母，还是从两边“同时”扫描
*/
class Solution {
public:
	string reverseVowels(string s) {
		char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		int length = s.length(), left = 0, right = length - 1;
		while (left < right) {
			while (left < length && !isVowel(s[left], vowels))
				++left;
			while (right >= 0 && !isVowel(s[right], vowels))
				--right;
			if (left >= right)
				break;
			swap(s[left], s[right]);
			++left;
			--right;
		}
		return s;
	}

	bool isVowel(char ch, char* vowels) {
		for (int i = 0; i < 10; ++i)
			if (ch == vowels[i])
				return true;
		return false;
	}
};

int main() {
	string a = "hello", b = "leetcode", c = "Ui";
	cout << a << " to be => " << Solution().reverseVowels(a) << endl;
	cout << b << " to be => " << Solution().reverseVowels(b) << endl;
	cout << c << " to be => " << Solution().reverseVowels(c) << endl;

	return 0;
}
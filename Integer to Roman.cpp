#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
#include "headers/TreeNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;
typedef TreeNodeTemplate<int> TreeNode;


/*
问题要求：
给定一个十进制的整数，要求返回其罗马数字形式

ps，数字的值保证在[1, 3999]
*/
class Solution {
public:
	/*// 打表反而更慢了？因为内存读取的问题？
	string intToRoman(int num) {
		string r_map[][10] = {
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "M", "MM", "MMM"}
		};
		
		string ans;
		int i = 0, now;
		while (num > 0) {
			now = num % 10;
			num /= 10;
			ans = r_map[i++][now] + ans;
		}
		return ans;
	}*/

	string intToRoman(int num) {
		char r_map[][2] = {
			{'I', 'V'},
			{'X', 'L'},
			{'C', 'D'},
			{'M', '\0'},
			{'\0'}
		};

		string ans;
		int i = 0, now, last = 0;
		while (num > 0) {
			now = num % 10;
			num /= 10;
			ans = i2r(now, r_map[i][0], r_map[i][1], r_map[i+1][0]) + ans;
			++i;
			last = now;
		}
		return ans;
	}

	string i2r(int x, char one, char five, char next) {
		if (x == 0)
			return "";
		if (x == 9) {
			string ans(2, one);
			ans[1] = next;
			return ans;
		}
		if (x == 4) {
			string ans(2, five);
			ans[0] = one;
			return ans;
		}
		if (x < 4)
			return string(x, one);
		string ans(1, five);
		return ans + string(x-5, one);
	}
};


int main() {
	for (int i = 1; i <= 20; ++i) {
		cout << i << ' ' << Solution().intToRoman(i) << endl << endl;;
	}

	assert(Solution().intToRoman(100) == "C");

	
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
模拟二进制数的加法
*/
class Solution {
public:
	string addBinary(string a, string b) {
		return BigIntegerAddition().add(a, b, 2);
	}

	class BigIntegerAddition {
	public:
		string add(string a, string b, size_t base=10) {
			size_t len = max(a.size(), b.size()) + 1, toAdd = 0, pos;
			align(a, len);
			align(b, len);

			string res(len, '0');
			for (size_t i = len; i > 0; --i) {
				pos = i - 1;
				toAdd += (a[pos] - '0') + (b[pos] - '0');
				res[pos] += toAdd % base;
				toAdd /= base;
			}
			clearZerosPrefix(res);
			return res;
		}

	private:
		void align(string& str, size_t len) {
			str.insert(str.begin(), len-str.size(), '0');
		}

		void clearZerosPrefix(string& a) {
			size_t pos = 0, len = a.size();
			while (pos < len && a[pos] == '0')
				++pos;
			if (pos == len)
				pos = len - 1;
			a = a.substr(pos);
		}
	};
};


int main() {
	cout << Solution().addBinary("11", "1") << endl;
	cout << Solution().addBinary("10", "111") << endl;

	return 0;
}
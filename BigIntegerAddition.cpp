#include <iostream>
#include <string>
using namespace std;


class BigIntegerAddition {
public:
	// 大整数使用字符串表示，base表示数字的基，默认为十进制
	string add(string a, string b, size_t base=10) {
		size_t len = max(a.size(), b.size()) + 1, toAdd = 0, pos;
		// 先补零，对齐两个数字
		align(a, len);
		align(b, len);

		string res(len, '0');
		for (size_t i = len; i > 0; --i) {
			// 可以稍微注意一下这里为何要用多一个pos来表示真正的下标，而i只是用来计数的
			// 因为size_t类型的最小值为0
			// 如果同时用下标来计数的话，是没法终止的，--0就变成很大的数字了
			pos = i - 1;
			toAdd += (a[pos] - '0') + (b[pos] - '0');
			res[pos] += toAdd % base;
			toAdd /= base;
		}
		clearZerosPrefix(res);	// 由于前面补零，有可能最后最高位并没有进位，所以有多余的零需要去掉
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


int main() {
	cout << BigIntegerAddition().add("233", "666") << endl;
	cout << BigIntegerAddition().add("0", "99") << endl;
	cout << BigIntegerAddition().add("1", "99") << endl;
	cout << BigIntegerAddition().add("101", "99") << endl;
	cout << BigIntegerAddition().add("0", "000") << endl;

	cout << BigIntegerAddition().add("101", "1", 2) << endl;
	cout << BigIntegerAddition().add("111", "11", 2) << endl;

	return 0;
}
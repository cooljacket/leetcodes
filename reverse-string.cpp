#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
	string reverseString(string s) {
		string res(s);
		for (int i = 0, j = s.size()-1; i < j; ++i, --j)
			swap(res[i], res[j]);
		return res;
	}
};


int main() {
	string s("hello world");
	string rs = Solution().reverseString(s);
	cout << "Before, s is " << s << endl;
	cout << "Then, s is " << rs << endl;

	return 0;
}
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;

// imitate plus hand computation
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int up = 1;
		vector<int> res(digits);
		for (int i = digits.size()-1; i >= 0; --i) {
			res[i] += up;
			if (res[i] >= 10)
				up = res[i] / 10;
			else
				up = 0;
			res[i] -= up * 10;
		}

		if (up > 0)
			res.insert(res.begin(), up);
		return res;
	}
};

void print(const vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		printf("%d", v[i]);
	printf("\n");
}

int main() {
	Solution s;
	
	vector<int> v;
	for (int i = 0; i < 3; ++i)
		v.push_back(0);

	print(v);
	vector<int> vv = s.plusOne(v);
	print(vv);

	return 0;
}
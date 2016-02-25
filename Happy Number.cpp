#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
using namespace std;


class Solution {
public:
	bool isHappy(int n) {
		set<int> s;
		while (true) {
			int sum = square_sum(n);
			if (sum == 1)
				return true;
			if (s.find(sum) != s.end())
				return false;
			s.insert(sum);
			n = sum;
		}
	}

	int square_sum(int n) {
		int sum = 0, d = 0;
		while (n > 0) {
			d = n % 10;
			n /= 10;
			sum += d*d;
		}

		return sum;
	}
};

int main() {
	Solution s;

	assert(s.isHappy(1) == true);
	assert(s.isHappy(91) == true);
	assert(s.isHappy(19) == true);

	return 0;
}
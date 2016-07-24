#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		return a + b;
	}
};


int main() {
	cout << Solution().getSum(233, 666) << endl;
	return 0;
}
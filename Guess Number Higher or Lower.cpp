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

int n = 2126753390;

/*
问题要求：
有一个外部给定的guess函数会给你一个结果，表示你猜的数字是比给定的数字高了还是低了，还是刚好相等，你自己猜出那个给定的数字是多少
*/

int guess(int num);

class Solution {
public:
	// 思路，典型的二分法啦
	int guessNumber(int n) {
		long long low = 1, high = n, mid, res;
		while (low <= high) {
			mid = (low + high) >> 1;
			res = guess(mid);
			if (res == 0)
				return mid;
			else if (res < 0)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return low;
	}
};


int main() {
	cout << Solution().guessNumber(1702766719) << endl;
	return 0;
}


int guess(int num) {
	if (num > n)
		return -1;
	if (num < n)
		return 1;
	return 0;
}
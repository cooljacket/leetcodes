#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;

int v = 5;

/*
问题要求：
一个产品的每一代都是基于上一代来开发的，上一个是坏的，那么这一次也是坏的。
求以最少的次数，找出第一个开始坏的版本。
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	// 思路：典型的二分法。
	// 注意是从1开始，而不是从0开始的
	int firstBadVersion(int n) {
		long long left = 1, right = n, mid;
		while (left < right) {
			mid = (left + right) >> 1;
			bool bad = isBadVersion(mid);
			if (!bad)
				left = mid + 1;
			else right = mid;
		}
		return left;
	}
};


int main() {
	cout << Solution().firstBadVersion(7) << endl;


	v = 1702766719;
	cout << Solution().firstBadVersion(2126753390) << endl;

	return 0;
}

bool isBadVersion(int version) {
	return version >= v;
}
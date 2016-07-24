#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
计算比n小的素数的个数

判断一个数字是否为素数的时间复杂度是O(sqrt(n))，如果直接做，总的时间复杂度就是O(n^1.5)，这个太慢了
*/
class Solution {
public:
	// 如果n不是很大的话，就直接用筛法，打表，复杂度为O(nlog n)，至于为什么是这样のlater
	int countPrimes(int n) {
		vector<bool> isPrime(n, true);
		int cnt = 0;
		for (int i = 2; i < n; ++i) {
			if (!isPrime[i])
				continue;
			++cnt;
			for (int j = (i << 1); j < n; j += i)
				isPrime[j] = false;
		}
		return cnt;
	}
};


int main() {
	assert(Solution().countPrimes(2) == 0); 
	assert(Solution().countPrimes(3) == 1); 
	assert(Solution().countPrimes(4) == 2); 
	assert(Solution().countPrimes(10) == 4);
	return 0;
}
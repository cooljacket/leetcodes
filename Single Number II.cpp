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
给定一个数组，里面除了一个元素只出现一次之外，其它元素都恰好出现了三次，求落单的元素
*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bits_cnt(32, 0);
		for (int i = 0; i < nums.size(); ++i)
			extractBits(nums[i], bits_cnt);
		return bits2int(bits_cnt);
	}

private:
	void extractBits(int x, vector<int>& bits_cnt) {
		for (int i = 0; i < 32; ++i) {
			if ((x & (1 << i)) != 0)
				bits_cnt[i] += 1;
		}
	}

	int bits2int(const vector<int>& bits_cnt) {
		int ans = 0;
		for (int i = 0; i < 32; ++i)
			if (bits_cnt[i] % 3 > 0)
				ans |= (1 << i);
		return ans;
	}
};


int main() {
	int arr[] = {1, 2, 3, 2, 2, 1, 1};
	vector<int> nums = arr2vec(arr, 7);
	assert(Solution().singleNumber(nums) == 3);

	return 0;
}
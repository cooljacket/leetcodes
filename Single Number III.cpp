#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
给定一个数组，里面除了两个元素只出现一次之外，其它的所有元素都恰好出现了两次，求这两个元素
*/
class Solution {
public:
	// 思路，先异或全部数字，假设要求的两个数字为x和y，xor_all = x ^ y
	// 由于x和y是不同的，所以它们的二进制形式肯定至少有一个位是不一样的
	// 而x & (x - 1)可以消去x最低的一个1，然后再和x自己异或一下，就得到那个唯一的位了！
	// 因为其它的位都保持一样，异或后都变成了零！！！
	// 最后的最后，根据这一位，把整个数组分成两部分，分别异或，可以得到最终的结果！
	vector<int> singleNumber(vector<int>& nums) {
		int xor_all = 0, len = nums.size();
		for (int i = 0; i < len; ++i)
			xor_all = xor_all ^ nums[i];

		int key = (xor_all & (xor_all - 1)) ^ xor_all;
		cout << key << ' ' << xor_all << endl;
		vector<int> res(2, 0);
		for (int i = 0; i < len; ++i) {
			if ((key & nums[i]) != 0)
				res[0] = res[0] ^ nums[i];
			else
				res[1] = res[1] ^ nums[i];
		}

		return res;
	}
};


int main() {
	int arr[] = {1, 2, 1, 3, 2, 5};
	vector<int> nums = arr2vec(arr, 6);
	vector<int> res = Solution().singleNumber(nums);
	display_v(res);

	return 0;
}
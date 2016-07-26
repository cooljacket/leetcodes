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
找出出现最频繁的前K个元素
*/
class Solution {
public:
	// 思路：用map或哈希表来计数，然后关键是找出频率最高的K个，我的方法有：
	// 1）排序后截取前K个；
	// 2）用插入排序维护一个大小为K个数组，时间复杂度为O(NK)
	// 3）用最小堆维护一个大小为K的堆，时间复杂度为O(Nlog K)
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> count;
		int len = nums.size();
		for (int i = 0; i < len; ++i)
			++count[nums[i]];
		return getTopK(count, k);
	}

private:
	template<typename KEY, typename VALUE>
	vector<KEY> getTopK(const map<KEY, VALUE>& m, int k) {
		int size = -1, capacity = k;
		vector<KEY> keys(capacity + 1);
		vector<VALUE> values(capacity + 1);
		typename map<KEY, VALUE>::const_iterator it = m.begin();
		while (it != m.end()) {
			size = min(size + 1, capacity);
			int index = size - 1;
			while (index >= 0 && it->second > values[index]) {
				keys[index+1] = keys[index];
				values[index+1] = values[index];
				--index;
			}
			keys[index+1] = it->first;
			values[index+1] = it->second;
			++it;
		}

		return vector<KEY>(keys.begin(), keys.begin() + k);
	}
};


int main() {
	int arr[] = {1 ,1 ,1 ,2 ,2 , 3};
	vector<int> nums = arr2vec(arr, 6);
	vector<int> res = Solution().topKFrequent(nums, 2);
	display_v(res);

	int arr2[] = {-1, -1};
	vector<int> nums2 = arr2vec(arr2, 2);
	vector<int> res2 = Solution().topKFrequent(nums2, 1);
	display_v(res2);

	return 0;
}
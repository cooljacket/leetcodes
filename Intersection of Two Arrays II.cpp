#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "headers/utils.h"
using namespace std;


/*
问题描述：
要求出两个数组里值相同且其出现次数要一样的元素，结果可以任意次序，不去重。

扩展：
1）如果给定的数组是有序的，你怎么优化你的算法？
2）如果nums1的大小远远小于nums2的大小，哪个算法更好？
3）如果nums2是有序的，存放在磁盘里，内存是有限的且你没法将所有元素一次性放进内存里，你会怎么做？
*/
class Solution {
public:
	// 问题分析：其实这个问题只是把同时在两个数组里出现的元素的”次数做交集“而已
	// 比如2在nums1里出现3次，而只在nums2里出现1次，那么结果的数组里只有一个2
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> m1, m2;
		vec_count_to_map(nums1, m1);
		vec_count_to_map(nums2, m2);

		vector<int> ans;
		map<int, int>::iterator it = m1.begin(), it2;
		while (it != m1.end()) {
			it2 = m2.find(it->first);
			if (it2 != m2.end()) {
				insertXTimes(ans, it->first, min(it->second, it2->second));
			}
			++it;
		}

		return ans;
	}

	void vec_count_to_map(const vector<int>& vec, map<int, int>& m) {
		for (int i = 0; i < vec.size(); ++i)
			++m[vec[i]];
	}

	void insertXTimes(vector<int>& vec, int element, size_t times) {
		vector<int> eles(times, element);
		vec.insert(vec.end(), eles.begin(), eles.end());
	}
};


int main() {
	int a1[] = {1, 2, 2, 1, 3};
	int a2[] = {2, 2, 1, 3};
	vector<int> v1 = arr2vec(a1, 5);
	vector<int> v2 = arr2vec(a2, 4);
	vector<int> intersection = Solution().intersect(v1, v2);
	display_v(intersection);

	return 0;
}
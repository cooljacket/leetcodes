#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include "headers/utils.h"
using namespace std;


/*
问题要求：求两个数组的交集，并对结果进行去重
*/
class Solution {
public:
	// 最笨的方法：两重循环，时间复杂度为O(MN)
	// 较好的方法：对一方建树或哈希表，另一方在树里做查找，时间复杂度可降为O(Nlog M)甚至O(N)
	// 注意点：最后的结果要去除重复，而不是傻傻地把所有结果统统push back到vector后返回
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1, s12;
		vec2set(nums1, s1);
		for (int i = 0; i < nums2.size(); ++i) {
			if (s1.find(nums2[i]) != s1.end())
				s12.insert(nums2[i]);
		}
		return set2vec(s12);
	}

	void vec2set(const vector<int>& vec, set<int>& s) {
		for (int i = 0; i < vec.size(); ++i)
			s.insert(vec[i]);
	}

	vector<int> set2vec(const set<int>& s) {
		vector<int> ans(s.size());
		size_t index = 0;
		set<int>::const_iterator it = s.begin();
		while (it != s.end()) {
			ans[index++] = *it;
			++it;
		}

		return ans;
	}
};


int main() {
	int a1[] = {1, 2, 2, 1, 3};
	int a2[] = {2, 2, 1};
	vector<int> v1 = arr2vec(a1, 5);
	vector<int> v2 = arr2vec(a2, 3);
	vector<int> intersection = Solution().intersection(v1, v2);
	display_v(intersection);

	return 0;
}
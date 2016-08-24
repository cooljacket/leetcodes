#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
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
给定一个升序的数组，和一个数字target，要求返回其中两个数字的下标，它们的和刚好等于target
下标是从1开始算的
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> index(2);
		int left = 0, right = numbers.size() - 1;
		while (left < right) {
			int sum = numbers[left] + numbers[right];
			if (sum == target) {
				index[0] = left + 1;
				index[1] = right + 1;
				break;
			} else if (sum > target) {
				--right;
			} else {
				++left;
			}
		}

		return index;
	}
};


int main() {
	int arr1[] = {2, 7, 11, 15, 20};
	vector<int> vec1 = arr2vec(arr1, 5);
	vector<int> index = Solution().twoSum(vec1, 9);
	display_v(index);

	return 0;
}
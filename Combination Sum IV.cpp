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

*/

// dfs太慢了
// class Solution {
// public:
// 	int combinationSum4(vector<int>& nums, int target) {
// 		sort(nums.begin(), nums.end());
// 		vector<int> elementCount(nums.size(), 0);
// 		int count = 0;
// 		dfs(nums, -1, elementCount, 0, target, count);
// 		return count;
// 	}

// private:
// 	void dfs(const vector<int>& nums, int lastPosition, vector<int> elementCount, int currentSum, int target, int& count) {
// 		int pos = lastPosition + 1;
// 		if (pos >= nums.size())
// 			return;
// 		int maxNumber = (target - currentSum) / nums[pos];
// 		for (int i = 0; i <= maxNumber; ++i, currentSum+=nums[pos]) {
// 			elementCount[pos] = i;
// 			if (currentSum == target) {
// 				count += cal(elementCount, nums);
// 				return;
// 			}
// 			dfs(nums, pos, elementCount, currentSum, target, count);
// 		}
// 	}

// 	typedef double LL;

// 	int cal(const vector<int>& elementCount, const vector<int>& nums) {
// 		LL last = 0, now = 0, result = 1;
// 		for (int i = 0; i < elementCount.size(); ++i) {
// 			if (elementCount[i] > 0) {
// 				now += elementCount[i];
// 				int maxOne = max(last, (LL)elementCount[i]);
// 				int minOne = min(last, (LL)elementCount[i]);
// 				result *= factorial(now, maxOne) / factorial(minOne);
// 				last = now;
// 				// cout << nums[i] << '*' << elementCount[i] << '\t';
// 			}
// 		}
// 		// cout << endl;
// 		// cout << "Then " << result << endl;
// 		return result;
// 	}

// 	LL factorial(int n, int start=1) {
// 		LL result = 1;
// 		for (int i = start+1; i <= n; ++i)
// 			result *= i;
// 		return result;
// 	}
// };


class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> count(target+1);
		count[0] = 1;
		for (int i = 1; i <= target; ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (i >= nums[j])
					count[i] += count[i-nums[j]];
			}
		}
		return count[target];
	}
};


int main() {
	int arr1[] = {1, 2, 3};
	vector<int> vec1 = arr2vec(arr1, 3);
	assert(Solution().combinationSum4(vec1, 4) == 7);

	// int arr2[] = {1, 50};
	// vector<int> vec2 = arr2vec(arr2, 2);
	// Solution().combinationSum4(vec2, 200) << endl;

	int arr3[] = {5, 1, 8};
	vector<int> vec3 = arr2vec(arr3, 3);
	assert(Solution().combinationSum4(vec3, 24) == 982);

	int arr4[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	vector<int> vec4 = arr2vec(arr4, sizeof(arr4)/sizeof(int));
	// assert(Solution().combinationSum4(vec4, 31) == 982);
	cout << Solution().combinationSum4(vec4, 31) << endl;

	return 0;
}
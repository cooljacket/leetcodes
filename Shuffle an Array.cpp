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

*/
class Solution {
public:
	Solution(vector<int> nums)
	: data(nums) {}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return data;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> copy(data);
		random_shuffle(copy.begin(),copy.end());
		return copy;
	}

private:
	vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */


int main() {
	

	return 0;
}
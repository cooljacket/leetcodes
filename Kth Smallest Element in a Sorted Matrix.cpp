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
	int kthSmallest(vector<vector<int> >& matrix, int k) {
		int n = matrix.size();
		int left = matrix[0][0], right = matrix[n-1][n-1], mid;
		while (left < right) {
			mid = (left + right) >> 1;
			int num = 0;
			for (int i = 0; i < n; ++i) {
				int numLeq = countLeq(matrix[i], mid);
				if (numLeq == 0)
					break;
				num += numLeq;
			}
			if (num < k)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}

private:
	// 找出vec中小于等于target的元素个数
	int countLeq(const vector<int>& vec, int target) {
		if (!vec.empty() && vec[0] > target)
			return 0;
		int low = 0, high = vec.size() - 1, mid;
		while (low < high) {
			mid = (low + high + 1) >> 1;
			if (vec[mid] > target)
				high = mid - 1;
			else
				low = mid;
		}
		return low + 1;
	}
};


int main() {
	

	return 0;
}
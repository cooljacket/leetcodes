#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;


class Solution {
public:
	/*
	// this version need O(m+n) space
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index1 = 0, index2 = 0, len = 0;
		vector<int> res(nums1.size());
		while (index1 < m || index2 < n) {
			if (index1 >= m)
				res[len++] = nums2[index2++];
			else if (index2 >= n)
				res[len++] = nums1[index1++];
			else {
				if (nums1[index1] <= nums2[index2])
					res[len++] = nums1[index1++];
				else
					res[len++] = nums2[index2++];
			}
		}

		for (int i = 0; i < res.size(); ++i)
			nums1[i] = res[i];
	}*/

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index1 = m-1, index2 = n-1, index = nums1.size()-1;
		while (index1 >= 0 || index2 >= 0) {
			if (index1 < 0)
				nums1[index--] = nums2[index2--];
			else if (index2 < 0)
				nums1[index--] = nums1[index1--];
			else {
				if (nums1[index1] > nums2[index2])
					nums1[index--] = nums1[index1--];
				else
					nums1[index--] = nums2[index2--];
			}
		}
	}
};

vector<int> gen(int size) {
	vector<int> data(size);
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
		data[i] = rand() % 100;

	sort(data.begin(), data.end());
	return data;
}

void print(const vector<int>& v, int size=-1) {
	if (size == -1)
		size = v.size();
	for (int i = 0; i < size; ++i)
		printf("%d ", v[i]);
	printf("\n\n");
}

int main() {
	Solution s;
		
	vector<int> v1 = gen(9), v2 = gen(4);
	print(v1, 5);
	print(v2);
	s.merge(v1, 5, v2, 4);
	print(v1);

	return 0;
}
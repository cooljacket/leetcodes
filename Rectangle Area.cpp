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


// refer: http://blog.csdn.net/foreverling/article/details/46411069
class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area = rectArea(A, B, C, D) + rectArea(E, F, G, H);

		// no intersection
		if (A >= G || B >= H || C <= E || D <= F)
			return area;

		int top = min(D, H);
		int right = min(C, G);
		int bottom = max(B, F);
		int left = max(A, E);

		return area - rectArea(left, bottom, right, top);
	}

	int rectArea(int A, int B, int C, int D) {
		return (C - A) * (D - B);
	}
};


int main() {
	Solution s;

	assert(s.computeArea(0, 0, 1, 1, 0, 0, 2, 3) == 6);		// Rect_A contains Rect_B
	assert(s.computeArea(-2, -2, 1, 2, 2, 0, 3, 1) == 13);	// no intersection
	assert(s.computeArea(-2, -2, 1, 2, 0, 0, 3, 1) == 14);	// have intersection
	assert(s.computeArea(0, 0, 1, 1, 1, 0, 2, 1) == 2);		// neighbor border

	return 0;
}
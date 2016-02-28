#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;


class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row[2] = {vector<int>(rowIndex+1), vector<int>(rowIndex+1)};
		int last = 1;
		for (int i = 0; i <= rowIndex; ++i) {
			int now = 1 - last;
			row[now][0] = row[now][i] = 1;
			for (int j = 1; j < i; ++j)
				row[now][j] = row[last][j-1] + row[last][j];

			last = now;
		}

		return row[last];
	}
};

void print(const vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");
}

int main() {
	Solution s;
	
	vector<int> v = s.getRow(3);
	print(v);

	vector<int> v2 = s.getRow(4);
	print(v2);

	return 0;
}
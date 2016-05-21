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
	vector<vector<int> > generate(int numRows) {
		if (numRows == 0)
			return vector<vector<int> >();

		vector<vector<int> > tower(numRows);
		tower[0].push_back(1);
		for (int i = 1; i < numRows; ++i) {
			int row_size = i + 1;
			tower[i] = vector<int>(row_size, 1);
			for (int j = 1; j < row_size-1; ++j)
				tower[i][j] = tower[i-1][j-1] + tower[i-1][j];
		}

		return tower;
	}
};

void print(const vector<vector<int> >& v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j)
			printf("%d ", v[i][j]);
		printf("\n");
	}
}

int main() {
	Solution s;
	
	vector<vector<int> > vv = s.generate(5);
	print(vv);

	return 0;
}
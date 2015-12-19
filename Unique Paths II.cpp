// https://leetcode.com/problems/unique-paths-ii/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	if (obstacleGrid.empty())
    		return 0;
    	int RSize = obstacleGrid.size(), CSize = obstacleGrid[0].size();

        vector<vector<int> > dp = obstacleGrid;
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < RSize; ++i)
        	if (obstacleGrid[i][0] == 0)
        		dp[i][0] = dp[i-1][0];
        	else
        		dp[i][0] = 0;
        for (int i = 1; i < CSize; ++i)
        	if (obstacleGrid[0][i] == 0)
        		dp[0][i] = dp[0][i-1];
        	else
        		dp[0][i] = 0;

        for (int r = 1; r < RSize; ++r)
        	for (int c = 1; c < CSize; ++c) {
        		if (obstacleGrid[r][c] == 1)
        			dp[r][c] = 0;
        		else
        			dp[r][c] = dp[r][c-1] + dp[r-1][c];
        	}

        /*for (int i = 0; i < RSize; ++i)
        	for (int j = 0; j < CSize; ++j)
        		printf("i=%d, j=%d, dp=%d\n", i, j, dp[i][j]);*/

        return dp[RSize-1][CSize-1];
    }
};

int main() {
	int size;
	cin >> size;
	vector<vector<int> > obstacleGrid(size, vector<int>(size));

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			cin >> obstacleGrid[i][j];

	Solution s;
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}

/*
3
0 0 0
0 1 0
0 0 0
*/
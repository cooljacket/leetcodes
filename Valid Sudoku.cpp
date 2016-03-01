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
#include <iostream>
using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char> >& board) {
		int size = 9;
		// check each row
		for (int i = 0; i < size; ++i) {
			vector<int> num(size+1);
			for (int j = 0; j < size; ++j)
				if (board[i][j] >= '0' && board[i][j] <= '9')
					if (++num[int(board[i][j] - '0')] > 1)
						return false;
		}

		// check each column
		for (int i = 0; i < size; ++i) {
			vector<int> num(size+1);
			for (int j = 0; j < size; ++j)
				if (board[j][i] >= '0' && board[j][i] <= '9')
					if (++num[int(board[j][i] - '0')] > 1)
						return false;
		}

		// check each grid
		for (int r = 0; r < 3; ++r)
			for (int c = 0; c < 3; ++c) {
				vector<vector<int> > grid(3, vector<int>(3));
				for (int i = 0; i < 3; ++i)
					for (int j = 0; j < 3; ++j) {
						char key = board[r*3+i][c*3+j];
						if (key >= '0' && key <= '9')
							grid[i][j] = int(key - '0');
						else
							grid[i][j] = -100;
					}
				if (!checkGrid(grid))
					return false;
			}

		return true;
	}

	bool checkGrid(const vector<vector<int> >& grid) {
		int size = 3;
		vector<int> num(10);

		// check each row
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (grid[i][j] > 0 && ++num[grid[i][j]] > 1)
					return false;
			}
		}
		return true;
	}
};



int main() {
	Solution s;

	int size = 9;
	vector<vector<char> > board(size, vector<char>(size));
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			cin >> board[i][j];

	s.isValidSudoku(board);

	return 0;
}
/*
....5..1.
.4.3.....
.....3..1
8......2.
..2.7....
.15......
.....2...
.2.9.....
..4......
false


.87654321
2........
3........
4........
5........
6........
7........
8........
9........
true
*/
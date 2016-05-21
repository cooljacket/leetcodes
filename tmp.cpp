// https://leetcode.com/problems/perfect-squares/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		//k = min(k, (int)prices.size());
		return helper(prices, k);
	}

	int helper(vector<int>& prices, int k) {
		int n = prices.size(), largest = 0, key = 1;
		vector<vector<int> > global(2, vector<int>(k+1)), local(global);
		for (int i = 1; i < n; ++i) {
			int diff = prices[i] - prices[i-1];
			for (int j = 1; j <= k; ++j) {
				local[key][j] = max(global[key-1][j-1]+max(diff, 0), local[key-1][j]+diff);
				global[key][j] = max(global[key-1][j], local[i][j]);
				largest = max(largest, global[i][j]);
			}
			key = 1 - key;
		}
		return largest;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	Solution s;
	cout << s.maxProfit(n, v) << endl;

	/*string s1;
	while (cin >> s1) {
		Solution s;
		cout << s.minDistance(s1) << endl;
	}*/

	/*string s1, s2;
	while (cin >> s1 >> s2) {
		Solution s;
		cout << s.isScramble(s1, s2) << endl;
	}*/

	/*
	string s1, s2, s3;
	while (cin >> s1 >> s2 >> s3) {
		Solution s;
		cout << s.isInterleave(s1, s2, s3) << endl;
	}*/
	
	return 0;
}

/*
2
1 2 4
*/
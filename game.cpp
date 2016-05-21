// https://leetcode.com/problems/perfect-squares/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	bool digit = false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != '-' && (s[i] > '9' || s[i] < '0')) {
			if (digit) {
				digit = false;
				cout << ' ';
			}
			continue;
		}
		else
			digit = true;
		cout << s[i];
	}	
	return 0;
}

/*
-7 -2 1 -5 -5 9 -4 -5 4 4 -6 -6 2 -1 -5 3 7 8 -3 7 -9 -9 -1 -9 6 9 0 7 -7 0 -6 -8 7 1 -4 9 -3 2
-6 -9 -7 -6 -9 4 0 -8 -6 -3 -9 -2 -6 7 -5 0 7 -9 -1 -2 4 -2 4 4 -1 2 -5 5 1 1 -6 1 -2 -4 4 -2 6
-6 0 6 -3 -3 -6 -2 -6 -2 7 -9 -5 -7 -5 5 1
-------------------
请按任意键继续. . .
*/
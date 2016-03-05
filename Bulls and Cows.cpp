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
#include <cmath>
#include <sstream>
using namespace std;


/*class Solution {
public:
	string getHint(string secret, string guess) {
		vector<bool> taken(guess.size(), false);
		int numOfBull = 0, numOfCow = 0;

		for (int i = 0; i < guess.size(); ++i) {
			if (guess[i] == secret[i]) {
				taken[i] = true;
				++numOfBull;
			}
		}

		for (int i = 0; i < guess.size(); ++i) {
			if (guess[i] != secret[i]) {
				for (int j = 0; j < secret.size(); ++j)
					if (!taken[j] && secret[j] == guess[i]) {
						++numOfCow;
						taken[j] = true;
						break;
					}
			}
			// printf("numOfBull=%d, numOfCow=%d\n", numOfBull, numOfCow);
		}

		stringstream ss;
		ss << numOfBull << 'A' << numOfCow << 'B';

		return ss.str();
	}
};*/

// a more quick version
class Solution {
public:
	string getHint(string secret, string guess) {
		vector<bool> taken(guess.size(), false);
		vector<int> s_cnt(10), g_cnt(10);
		int numOfBull = 0, numOfCow = 0;

		for (int i = 0; i < guess.size(); ++i) {
			if (guess[i] == secret[i]) {
				taken[i] = true;
				++numOfBull;
			}
			else {
				++s_cnt[int(secret[i]-'0')];
				++g_cnt[int(guess[i]-'0')];
			}
		}

		for (int i = 0; i < s_cnt.size(); ++i)
			numOfCow += min(s_cnt[i], g_cnt[i]);

		stringstream ss;
		ss << numOfBull << 'A' << numOfCow << 'B';

		return ss.str();
	}
};


int main() {
	Solution s;

	assert(s.getHint("1807", "7810") == "1A3B");
	assert(s.getHint("1123", "0111") == "1A1B");
	assert(s.getHint("011", "110") == "1A2B");

	return 0;
}
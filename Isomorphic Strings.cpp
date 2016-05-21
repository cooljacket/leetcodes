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
	// a low speed version
	bool isIsomorphic(string s, string t) {
		map<char, char> s_map, t_map;
		int size = s.size();
		for (int i = 0; i < size; ++i) {
			if (s_map.find(s[i]) == s_map.end()) {
				if (t_map.find(t[i]) != t_map.end())
					return false;
				s_map[s[i]] = t[i];
				t_map[t[i]] = s[i];
			}
			else if (s_map[s[i]] != t[i])
				return false;
		}

		return true;
	}*/

	// a quick solution! because char in range [-128, 127]
	bool isIsomorphic(string s, string t) {
		vector<char> s_map(256, 0), t_map(256, 0);
		int size = s.size();
		for (int i = 0; i < size; ++i) {
			if (s_map[s[i]+128] == 0) {
				if (t_map[t[i]+128] != 0)
					return false;
				s_map[s[i]+128] = t[i];
				t_map[t[i]+128] = s[i];
			}
			else if (s_map[s[i]+128] != t[i])
				return false;
		}

		return true;
	}
};


int main() {
	Solution s;

	assert(s.isIsomorphic("add", "egg") == true);
	assert(s.isIsomorphic("foo", "bar") == false);
	assert(s.isIsomorphic("paper", "title") == true);
	assert(s.isIsomorphic("abba", "abab") == false);
	assert(s.isIsomorphic("ab", "aa") == false);
	assert(s.isIsomorphic("233", "666") == false);


	return 0;
}
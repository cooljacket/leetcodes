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


class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<char, string> cs_map;
		map<string, char> sc_map;
		vector<string> vs = split(str);
		if (vs.size() != pattern.size())
			return false;

		for (int i = 0; i < pattern.size(); ++i) {
			if (cs_map.find(pattern[i]) == cs_map.end()) {
				if (sc_map.find(vs[i]) != sc_map.end())
					return false;
				cs_map[pattern[i]] = vs[i];
				sc_map[vs[i]] = pattern[i];
			}
			else if (cs_map[pattern[i]] != vs[i]) {
				return false;
			}
		}

		return true;
	}

	vector<string> split(const string& str) {
		vector<string> vs;
		stringstream ss(str);
		string a;
		while (ss >> a)
			vs.push_back(a);

		return vs;
	}

};


int main() {
	Solution s;

	assert(s.wordPattern("abba", "dog cat cat dog") == true);
	assert(s.wordPattern("abba", "dog cat cat fish") == false);
	assert(s.wordPattern("aaaa", "dog cat cat dog") == false);
	assert(s.wordPattern("abba", "dog dog dog dog") == false);

	return 0;
}
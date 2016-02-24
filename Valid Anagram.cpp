#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <assert.h>
using namespace std;


class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		vector<int> scnt(26), tcnt(26);
		deal(s, scnt);
		deal(t, tcnt);

		for (int i = 0; i < scnt.size(); ++i)
			if (scnt[i] != tcnt[i])
				return false;

		return true;
	}

	void deal(const string& s, vector<int>& cnt) {
		for (int i = 0; i < s.size(); ++i)
			if (s[i] >= 'a' && s[i] <= 'z')
				++cnt[s[i] - 'a'];
	}
};


int main() {
	Solution s;

	assert(s.isAnagram("abcd", "badc") == true);
	assert(s.isAnagram("car", "rat") == false);
	assert(s.isAnagram("anagram", "nagaram") == true);

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;


/*
问题要求：
对比版本号大小
*/
class Solution {
public:
	// 思路：版本号分割，补零对齐长度，逐位比较
	int compareVersion(string version1, string version2) {
		Version v1(version1), v2(version2);
		return v1.compare(v2);
	}

private:
	class Version{
	public:
		Version(string v_str) {
			int left = 0, right = 0, len = v_str.size();
			while (left < len) {
				while (right < len && v_str[right] != '.')
					++right;
				X.push_back(str2int(v_str.substr(left, right)));
				left = ++right;
			}
		}

		int compare(Version& v) {
			int xLen = X.size(), vxLen = v.X.size();
			int len = max(xLen, vxLen);
			align(len);
			v.align(len);
			for (int i = 0; i < len; ++i) {
				if (X[i] < v.X[i])
					return -1;
				if (X[i] > v.X[i])
					return 1;
			}
			return 0;
		}

	private:
		vector<int> X;

		int str2int(const string& s) {
			stringstream ss(s);
			int ans;
			ss >> ans;
			return ans;
		}

		void align(int len) {
			for (int i = X.size(); i < len; ++i)
				X.push_back(0);
		}
	};
};


int main() {
	// 0.1 < 1.1 < 1.2 < 13.37
	assert(Solution().compareVersion("0.1", "1.1") == -1);
	assert(Solution().compareVersion("13.37", "1.2") == 1);
	assert(Solution().compareVersion("1.52", "1.52") == 0);
	assert(Solution().compareVersion("1.0.1", "1") == 1);
	assert(Solution().compareVersion("1.0.0", "1") == 0);

	return 0;
}
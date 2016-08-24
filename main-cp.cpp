#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "headers/utils.h"
#include "headers/ListNodeTemplate.h"
#include "headers/TreeNodeTemplate.h"
using namespace std;

typedef ListNodeTemplate<int> ListNode;
typedef TreeNodeTemplate<int> TreeNode;


/*
问题要求：

*/

void replaceBlank(char* str) {
	if (str == NULL)
		return;
	int countOfSpace = 0;
	char* now = str;
	while (*now != '\0') {
		if (*now++ == ' ')
			++countOfSpace;
	}

	if (countOfSpace == 0)
		return;

	char* newStr = now + (countOfSpace << 1);
	while (now >= str) {
		if (*now == ' ') {
			*newStr-- = '0';
			*newStr-- = '2';
			*newStr-- = '%';
		} else {
			*newStr-- = *now;
		}
		--now;
	}
}

int main() {
	char str1[] = "hello jacket, good night\0aaaaaaaaaa";
	cout << str1 << endl;
	replaceBlank(str1);
	cout << str1 << endl;

	return 0;
}
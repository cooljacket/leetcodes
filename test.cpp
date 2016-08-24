#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void mergeSortedArray(vector<int>& v1, const vector<int>& v2, int size1) {
	int allIndex = size1 + v2.size() - 1, index1 = size1 - 1, index2 = v2.size() - 1;
	while (index1 >= 0 || index2 >= 0) {
		if (index1 < 0)
			v1[allIndex--] = v2[index2--];
		else if (index2 < 0)
			v1[allIndex--] = v1[index1--];
		else {
			if (v1[index1] >= v2[index2])
				v1[allIndex--] = v1[index1--];
			else
				v1[allIndex--] = v2[index2--];
		}
	}
}


vector<int> genData(size_t size) {
	static const int MAX = 100;
	vector<int> res(size);
	for (size_t i = 0; i < size; ++i) {
		res[i] = rand() % MAX;
	}

	sort(res.begin(), res.end());
	return res;
}

void display(const vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ' ';
	cout << endl;
}

int main() {
	srand(time(0));
	vector<int> v1 = genData(5);
	vector<int> v2 = genData(6);

	display(v1);
	display(v2);
	v1.insert(v1.end(), v2.begin(), v2.end());
	mergeSortedArray(v1, v2, 5);
	display(v1);

	return 0;
}
// https://leetcode.com/problems/ugly-number-ii/
// 注意要用LL，否则会溢出产生负数之类的“小数”

class Solution {
public:
	typedef long long LL;

    // int nthUglyNumber(int n) {
    //     priority_queue<LL, vector<LL>, greater<LL> > q;
    //     set<LL> s;
    //     q.push(1);
    //     s.insert(1);
    //     LL num = 0, cnt;
    //     while (num < n) {
    //     	cnt = q.top();
    //     	q.pop();
    //     	if (s.find(cnt*2) == s.end()) {
    //     		q.push(cnt*2);
    //     		s.insert(cnt*2);
    //     	}
    //     	if (s.find(cnt*3) == s.end()) {
    //     		q.push(cnt*3);
    //     		s.insert(cnt*3);
    //     	}
    //     	if (s.find(cnt*5) == s.end()) {
    //     		q.push(cnt*5);
    //     		s.insert(cnt*5);
    //     	}
    //     	++num;
    //     }

    //     return cnt;
    // }
    int nthUglyNumber(int n) {
        int L2 = 1, L3 = 1, L5 = 1, ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans = min(2*L2, min(L3*3, L5*5));
            if (ans == 2*L2)
                ++L2;
            else if (ans == 3*L3)
                ++L3;
            else
                ++L5;
        }
        return ans;
    }
};
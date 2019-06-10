#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	string intToRoman(int num) {
    	vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    	vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    	string res = "";
    	for (int i=0; i<n.size(); i++) {
    		while (num >= n[i]) {
    			res += s[i];
    			num -= n[i];
    		}
    	}

    	return res;
    }
};

int main(void) {

	int n = 3382;

	Solution s;

	string res = s.intToRoman(n);
	cout << "n: " << n << ", res : " << res << endl;


	return 0;
}


// 点展： http://sia.baidu.com/p/feed#/conf/result/dashboard/filter~name=_1718281
// 
// 流量：
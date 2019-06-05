#include <iostream>
#include <vector>

using namespace std;

/*
	思路: 按行排序
 */

class Solution {
public:
	string convert(string s, int numRows) {
     	if (numRows == 1) return s;
     	vector<string> rows(min(numRows, int(s.size())));
     	int curRow = 0;

     	bool goingDown = false;

     	// 遍历字符串
     	for (char c : s) {
     		rows[curRow] += c;
     		if (curRow == 0 || curRow == numRows - 1)
     			goingDown = !goingDown;
     		curRow += goingDown ? 1 : -1;
     	}

     	string res = "";
    	for(int i=0; i<rows.size(); i++) {
    		res +=rows[i];
    	}
    	return res;
    }
};


int main(void) {
	// 代码测试
	string my_str = "PAYPALISHIRING";
	Solution *s = new Solution();
	string res = s->convert(my_str, 3);
	cout << res << endl; // "PAHNAPLSIIGYIR"

	delete s;
	return 0;
}
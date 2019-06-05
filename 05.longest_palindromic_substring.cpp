#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	P(i, j) => {   true : s[i, j] 是回文串
				   false: s[i, j] 不是回文串

	P(i, j) = (P(i+1, j-1) && s[i] == s[j]) 

	1. 动态方程式
	2. 边界条件

	Time: O(n^2)
	Space: O(n^2)

	baca

 */   

class Solution {
public:
	string long_palindromic_substring(string s) {
		// 字符串长度
		int n = s.size();
		// 返回的字符串
		string sub = "";

		// dp表，动态规划表
		vector<vector<bool>> dp(n, vector<bool>(n, false));

		for (int i=n-1; i>=0; i--) {
			for (int j=i; j<n; j++) {
				dp[i][j] = s[i] == s[j] && (j-i<2 || dp[i+1][j-1]); // j-i<2 , 标识字符串长度为1，2的情况

				// 这两个字符相等，并且字符串长度大于之前的长度
				// 
				// 
				// 重复利用了之前
				if (dp[i][j] && j-i+1 > sub.size()) {
					// 最长回文字符串
					sub = s.substr(i, j-i+1);
				}
			}
		}
		return sub;

	}
};

int main(int argc, char const *argv[])
{
	/* code */

	string str = "babad";
	Solution *s = new Solution;
	string res = s->long_palindromic_substring(str);
	cout << "res: " << res << endl;
	delete s;
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

/*
 动态规划：
 1. 状态转移方程：描述问题结构的数学形式
 2. 重叠子问题: 子问题被重复计算
 3. 最优子结构: 原问题的解由子问题的最优解构成


 



递归的暴力破解 -> 带备忘录的递归解法 -> 非递归的动态规划解法

递归可以通过画递归树的方式，分析算法的复杂度，和算法低效的原因

递归算法的时间复杂度怎么计算？子问题个数乘以解决一个子问题需要的时间。



 
 */

class Solution {
public:
	bool isMatch(string s, string p) {
        if (p.empty())
        	return s.empty();

        bool first_match = (!s.empty()) && (p[0] == s[0] || p[0] == '.');

        if (p.size() >=2 && p[1] == '*') {
        	return isMatch(s, p.substr(2)) // 匹配 0 个
        		||  ( first_match && isMatch(s.substr(1), p)); // 匹配1个
        } else {
        	return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }

    bool isMatch2(string s, string p) {
    	return true;
    }
};


int main(void) {

	string mystr = "aacd";
	string p = "a*.d";

	Solution * s = new Solution();
	bool res = s->isMatch(mystr, p);
	cout << "res: " << res << endl;


	delete s;
	return 0;
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

	// 思路
	// 
	// 回溯法？？？
	// 
	// 
	// 
	// 
	vector<string> letterCombinations(string digits) {
    	if (digits.empty())
    		return output;

    	unordered_map<char,string> my_map = {
    		{'2', "abc"},
    		{'3', "def"},
    		{'4', "ghi"},
    		{'5', "jkl"},
    		{'6', "mno"},
    		{'7', "pqrs"},
    		{'8', "tuv"},
    		{'9', "wxyz"}
    	};

    	comb("", digits, my_map);
    	return output;
    }

    void comb(string com, string dig, unordered_map<char,string>  &my_map) {
    	if (dig.empty()) {
    		output.push_back(com);
    	} else {
    		string item = my_map[dig[0]];
	    	for (int i=0; i<item.size(); i++) {
	    		// 没有返回
	    		comb(com+item[i], dig.substr(1), my_map);
	    	}
    	}
    }

    vector<string> output;
};


int main(void) {
	string dig = "239";

	Solution s;

	vector<string> res = s.letterCombinations(dig);

	for (int i=0; i<res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}
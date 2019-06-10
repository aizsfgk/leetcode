#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int roman_to_integer(string s) {
		if (s.empty())
			return 0;

		unordered_map<char, int> my_map = {
			{'M', 1000},
			{'D', 500},
			{'C', 100},
			{'L', 50},
			{'X', 10},
			{'V', 5},
			{'I', 1}
		};

		int ans = 0;
		for (int i=0; i<s.size(); i++) {
			if (i<s.size() -1 && my_map[s[i]] < my_map[s[i+1]]) {
				ans -= my_map[s[i]];
			} else {
				ans += my_map[s[i]];
			}
		}

		return ans;
	}
};

int main(void) {
	string str = "MDIV";

	Solution s;
	int res = s.roman_to_integer(str);

	cout << "str: " << str << ", res: " << res << endl;

	return 0;
}
#include <iostream>

using namespace std;

class Solution {
public:
	 bool isPalindrome(int x) {
	 	if (x < 0) {
	 		return false;
	 	}
	 	int rev = 0;
	 	int ori_x = x;
	 
	 	while (x != 0) {
	 		int pop = x % 10;
	 		x = x / 10;

	 		if (x > INT_MAX/10 || (x == INT_MAX/10 && pop >=7 ))
	 			return false;

	 		rev = rev * 10 + pop;
	 	}

	 	return rev == ori_x;
	 }
};

int main(void) {
	int x = 12121;

	Solution *s = new Solution();
	bool res = s->isPalindrome(x);

	cout << "x: "<< x<<", res: " << res << endl;

	delete s;
	return 0;
}
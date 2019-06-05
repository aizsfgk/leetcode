#include <iostream>
#include <vector>
#include <limits>


using namespace std;

class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			// 求出个位数
			int pop = x % 10;
			// 除去个位数
			x /= 10;

			//////// == 边界处理 == ////////////////
			if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7))
				return 0;
			if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8))
				return 0;
			

			rev = rev * 10 + pop;
		}
		return rev;
	}
};

int main(int argc, char const *argv[])
{
	int x = 3427891;
	Solution *s = new Solution();
	int r = s->reverse(x);

	cout << "r : " << r << endl;
	return 0;
}
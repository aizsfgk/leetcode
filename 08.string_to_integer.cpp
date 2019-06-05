#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
        int index = 0;
        int is_neg = false;
        int res = 0;

        while (str[index] == ' ')
        	index++;

        for (int i=index; i<str.size(); i++) {
        	if (str[i] == '-' && i == index)
        		is_neg = true;
        	if (str[i] < 48 || str[i] > 57)
        		break;

        	int pop = str[i] - 48;

        	if (is_neg) {
        		if (res < INT_MIN/10 || (res == INT_MIN/10 && pop < -8))
        			return INT_MIN;
        	} else {
        		if (res > INT_MAX/10 || (res == INT_MAX/10 && pop > 7))
        			return INT_MAX;
        	}
        	res = res * 10 + pop;
        }
        return is_neg ? -res : res;
    }
};

int main(int argc, char const *argv[])
{
	string str = "12321";
	Solution *s = new Solution();
	int re = s->myAtoi(str);

	cout << "re: " << re << endl;

	delete s;
	return 0;
}

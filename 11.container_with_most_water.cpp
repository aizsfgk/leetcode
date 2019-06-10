#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size() - 1, res = 0;

        while (i < j) {
        	int h = min(height[i], height[j]);
        	res = max(res, h * (j-i));

        	if (height[i] <= height[i]) {
        		++i;
        	} else {
        		--j;
        	}
        }
        return res;
    }
};


int main(void) {

	vector<int> h =  {1,8,6,2,5,4,8,3,7};
	Solution s; // 栈上分配，自动释放
	int res = s.maxArea(h);
	cout << "res: " << res << endl;
	
	return 0;
}
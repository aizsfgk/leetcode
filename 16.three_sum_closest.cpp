#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return 0;
    	sort(nums.begin(), nums.end());
    	int closest = nums[0] + nums[1] + nums[2];

    	for (int i=0; i<nums.size()-2; i++) {
    		int j = i+1, k= nums.size()-1;

    		while (j < k) {
    			int tmp = nums[i] + nums[j] + nums[k];
    			if (abs(tmp -target) < abs(closest - target))
    				closest = tmp;

    			if (tmp > target) {
    				k--;
    			} else if (tmp < target) {
    				j++;
    			} else {
    				return target;
    			}
    		}
    	}

    	return closest;
    }
};


// 最接近3数之和
int main(void) {

	vector<int> v = {-1,0, 3, 5,9,8};
	int target = 1;
	Solution s;
	int rs = s.threeSumClosest(v, target);

	cout << "target: " << target << ", res: " << rs << endl;

	return 0;
}
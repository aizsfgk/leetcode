#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        int n = nums.size();
        if ( n< 4)
            return res;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-3; i++) {

            for (int j=i+1; j<n-2; j++) {
                int k = j+1, l = n - 1;
                while (k < l) {

                    int tmp = nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if (tmp < target) {
                        while (nums[k] == nums[k+1]) k++;
                        k++;
                    } else if (tmp > target) {
                        while (nums[l] == nums[l-1]) l--;
                        l--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    }
                }
            }
        }
        return res;
    }
};


int main(void) {

	vector<int> v = {0,0,0,0};
	int t = 1;

	Solution s;
	vector<vector<int>> res;
	res = s.fourSum(v, t);

	for (int i=0; i<res.size(); i++) {
		for (int j=0; j<res[i].size(); j++) {
			cout << res[i][j] << "->";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
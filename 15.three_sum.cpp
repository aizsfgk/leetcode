#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

class Solution {
public:
	vector<vector<int>> three_sum(vector<int>& nums) {
		vector<vector<int>> res;

		if (nums.size() < 3)
			return res;

		sort(nums.begin(), nums.end());
		// for (int i=0; i<nums.size(); i++) {
		// 	cout << nums[i] << "->";
		// }
		// cout << endl;

		unordered_map<int, int> my_map;
		for (int i=0; i<nums.size(); i++) {
			my_map[nums[i]] = i;
		}
		


		for (int i=0; i<nums.size()-2; i++) {
			if (i == 0 || nums[i-1] != nums[i]) {
				for (int j=i+1; j<nums.size()-1; j++) {
					if (j == i+1 || nums[j-1] != nums[j]) {
						int target = -(nums[i] + nums[j]);
						auto iter = my_map.find(target);
						if (iter != my_map.end() && iter->second > j) {
							res.push_back({nums[i], nums[j], iter->first});
						}
					}
				}
			}
		}

		return res;
	}

};


int main(void) {
	vector<int> v = {-1, 0, 2, 1, -1, 3};

	Solution s;
	vector<vector<int>> res = s.three_sum(v);

	for (int i=0; i<res.size(); i++) {
		for (int j=0; j<res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
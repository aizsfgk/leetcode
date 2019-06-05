#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
 	两数之和：
 		1. 遍历数组，构建map
 		2. 查找map，有则构建2数之和
 */
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> my_map;
		vector<int> res;

		for (int i=0; i<nums.size(); i++) {
			my_map[nums[i]] = i;
		}

		for (int i=0; i<nums.size(); i++) {
			unordered_map<int, int>::iterator ele = my_map.find(target - nums[i]);
			if (ele != my_map.end() && ele->second > i) {
				res.push_back(nums[i]);
				res.push_back(ele->first);
			}
		}
		return res;
	}
};


int main(int argc, char const *argv[])
{
	Solution *s = new Solution();

	int target = 3;

	vector<int> nums = {1,2,3,4,5};

	vector<int> res;
	res = s->twoSum(nums, target);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << "i: " << i<< ", ele: " << res[i] << endl;
	}

	return 0;
}
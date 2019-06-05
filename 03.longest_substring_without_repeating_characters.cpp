#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:

	// 暴力破解
    // int lengthOfLongestSubstring(string s) {
    // 	int ans = 0;
    // 	int i,j;

    // 	for(i=0; i<s.size(); i++) {
    // 		for (j=i; j<s.size(); j++) {
    // 			string sub = s.substr(i, j-i+1);
    // 			if (isUniq(sub)) {
    // 				ans = max(ans, (int)sub.size());
    // 			}
    // 		}
    // 	}
    // 	return ans;
    // }

    // bool isUniq(string s) {
    // 	set<char> my_set;
    // 	for (int i=0; i<s.size(); i++) {
    // 		auto iter = my_set.find(s[i]);
    // 		if (iter != my_set.end())
    // 			return false;
    // 		my_set.insert(s[i]);
    // 	}
    // 	return true;
    // }
    
    // 滑动窗口
    // int lengthOfLongestSubstring(string s) {
    // 	set<char> my_set;
    // 	int len = s.size();
    // 	int i,j,ans;
    // 	i = j = ans = 0;

    // 	while (i<len && j<len) {
    // 		auto iter = my_set.find(s[j]);
    // 		if (iter == my_set.end()) {
    // 			my_set.insert(s[j]);
    // 			ans = max(ans, j-i+1);
    // 			j++; 			
    // 		} else {
    // 			my_set.erase(s[i]);
    // 			i++;
    // 		}
    // 	}
    // 	return ans;
    // }	


    // 优化的滑动窗口
    int lengthOfLongestSubstring(string s) {
    	map<char, int> my_map;

    	int i,j,ans;
    	i = j = ans;
    	int len = s.size();

    	while (i<len && j<len) {
    		auto iter = my_map.find(s[j]);
    		if (iter != my_map.end()) {
    			i = max(i, iter->second+1);
    		}
    		ans = max(ans, j-i+1);
    		my_map[s[j]] = j;

    		j++;
    	}
        
    	return ans;
    }
};




int main(int argc, char const *argv[])
{
	string str = "432dfdsaffdsaewerew234";
	Solution *s = new Solution();
	int len = s->lengthOfLongestSubstring(str);

	cout << "Len: " << len << endl;
	return 0;
}
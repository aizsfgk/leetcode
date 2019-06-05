#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        /*
    	int n = nums1.size();
    	int m = nums2.size();

    	if (n > m)
    		return findMedianSortedArrays(nums2, nums1);

    	// hi = 2*n 虚拟填充位#
    	int LMax1, LMax2, RMin1, RMin2, c1, c2, lo=0, hi=2*n;

    	while (lo <= hi) {
    		c1 = (lo + hi) / 2;
    		c2 = n + m - c1;

    		// 数组1，整个在中位数右边
    		LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
    		// 数组，整体在左边了
    		RMin1 = (c1 == 2*n) ? INT_MAX : nums1[c1 / 2];
    		// 数组2整体在右边
    		LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
    		// 数组2整体在左边
    		RMin2 = (c2 == 2*n) ? INT_MAX : nums2[c2 / 2];

    		// 
    		if (LMax1 > RMin2) 
    			hi = c1 - 1; // c1 向左二分
    		else if (LMax2 > RMin1)
    			lo = c1 + 1; // c1 向右二分
    		else
    			break;
    	}

    	return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;

    	*/
    
    	int n = nums1.size();
    	int m = nums2.size();

    	int i,j,mid_size, one, another;
    	i = j = mid_size = one = another = 0;

    	while (i<n && j<m && mid_size <=(n+m)/2) {
    		another = one;
    		if (nums1[i] <= nums2[j]) {
    			one = nums1[i];
    			i++;
    		} else {
    			one = nums2[j];
    			j++;
    		}
    		mid_size++;
    	}

    	while (mid_size <= (n+m)/2 && i<n) {
    		another = one;
    		one = nums1[i];
    		i++;
    		mid_size++;
    	}

    	while (mid_size <= (n+m)/2 && j<m) {
    		another = one;
    		one = nums2[j];
    		j++;
    		mid_size++;
    	}

    	if ((n+m)%2 == 0 )
    		return (another+one) / 2.0;
    	else
    		return one;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums1 = {1,3};
	vector<int> nums2 = {2,4,6,8};
	Solution * s = new Solution();
	double res = s->findMedianSortedArrays(nums1, nums2);

	cout << "res: " << res << endl;

	delete s;
	return 0;
}
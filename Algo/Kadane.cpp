#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int actualsum = 0, sumtotal = INT_MIN;

        for(int i = 0; i<nums.size(); i++){
            actualsum += nums[i];
            if(actualsum < nums[i]) actualsum = nums[i];
            if(sumtotal < actualsum) sumtotal = actualsum;
        }

        return sumtotal;
    }
};


int main(){
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	
	Solution sol;
	
	cout << sol.maxSubArray(nums) << endl;
	
}

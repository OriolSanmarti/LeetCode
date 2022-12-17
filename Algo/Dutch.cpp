#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size()-1;

        while(mid<=hi){
            switch(nums[mid]){
                case 0:
                    swap(nums[lo++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[hi--]);                   
                    break;
            }
        }
    }
};


int main(){
	vector<int> nums{0,1,2,1,2,2,0,0,1,1};
	
	for(auto x: nums){
		cout << x << " ";
	} cout << endl;
	
	Solution sol;
	sol.sortColors(nums);

	for(auto x: nums){
		cout << x << " ";
	}
	
}

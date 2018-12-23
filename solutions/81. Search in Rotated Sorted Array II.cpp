81. Search in Rotated Sorted Array II
/*
use binary search to find pivot
use binary search to get the result
25 min
cannot finish

6 min
bug free
time: O(logn)
space: O(1)
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // check empty
        if(nums.size()==0){
            return false;
        }
        // use binary search to find pivot
        
        return binary_search(nums, target);
    }
    bool binary_search(vector<int> nums, int target){
        int lo = 0;
        int hi = nums.size()-1;
        while(lo < hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]>nums[hi]){
                if(nums[mid]>target&&nums[lo]<=target) {
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            } else if(nums[mid]<nums[hi]){
                if(nums[mid]<target&&nums[hi]>=target){
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            } else {
                hi--;
            }
        }
        return nums[lo]==target? true:false;
    }
};
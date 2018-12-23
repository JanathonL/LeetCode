33. Search in Rotated Sorted Array
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
    int search(vector<int>& nums, int target) {
        // check empty
        if(nums.size()==0){
            return -1;
        }
        // use binary search to find pivot
        
        return binary_search(nums, target);
    }
    int binary_search(vector<int> nums, int target){
        int lo = 0;
        int hi = nums.size()-1;
        while(lo < hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>nums[hi]){
                if(nums[mid]>target&&nums[lo]<=target) {
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            } else{
                if(nums[mid]<target&&nums[hi]>=target){
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
        }
        return nums[lo]==target? lo:-1;
    }
};
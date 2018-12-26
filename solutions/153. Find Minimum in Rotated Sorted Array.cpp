153. Find Minimum in Rotated Sorted Array
/*
2 wrong
5 min
time: O(logn)
space: O(1)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi]){
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return nums[hi];  //注意返回index还是value
    }
};
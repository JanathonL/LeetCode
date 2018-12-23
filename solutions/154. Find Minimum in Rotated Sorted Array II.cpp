/*
bug free
2 min
time: O(logn) worst case O(N)
space: O(1)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi]){
                lo = mid+1;
            } else if(nums[mid]<nums[hi]){
                hi = mid;
            } else {
                hi -= 1;
            }
        }
        return nums[hi];
    }
};
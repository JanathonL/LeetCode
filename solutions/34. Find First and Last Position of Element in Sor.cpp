34. Find First and Last Position of Element in Sorted Array
/*
[5,7,7,8,8,10]
8
lo = 3
hi = 5
mid = 4
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int lo = find_equal(nums, target);
        int hi = find_hi(nums, target);
        if(lo==-1||hi==-1){
            return {-1,-1};
        } else {
            return {lo, hi};
        }
    }
    int find_equal(vector<int> nums, int target){
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>=target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(nums[lo]==target){
            return lo;
        } else {
            return -1;
        }
    }
    int find_hi(vector<int> nums, int target){
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(nums[hi]>target){
            return hi-1;
        } else if(nums[hi]==target){
            return hi;
        } else {
            return -1;
        }
    }
};

// refined
// beat 100%
// time: O(logn)
// space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = findSmall(nums, target);
        int hi = findLarge(nums, target);
        lo += 1;
        hi -= 1;
        if(lo>hi) return {-1,-1};
        else return {lo,hi};
    }
    int findSmall(vector<int> nums, int target){
        int lo=0, hi=nums.size()-1;
        while(lo<hi){
            int mid = lo + (hi-lo+1)/2;
            if(nums[mid]>=target){
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        if(lo<nums.size() && nums[lo]==target){
            return lo-1;
        } else {
            return lo;
        }
    }
    int findLarge(vector<int> nums, int target){
        int lo=0, hi=nums.size()-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]<=target){
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        if(hi>=0 && nums[hi]==target){
            return hi+1;
        } else {
            return hi;
        }
    }
    
};
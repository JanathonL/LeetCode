// 152. Maximum Product Subarray
// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> pos(nums.size(),1);
        vector<int> neg(nums.size(),1);
        neg[0]=pos[0]=nums[0];
        int maxcnt = nums[0];
        for(int i=1;i<nums.size();i++){
            int largest = INT_MIN;
            int smallest = INT_MAX;
            largest = max(max(neg[i-1]*nums[i],pos[i-1]*nums[i]),nums[i]);
            smallest = min(min(neg[i-1]*nums[i],pos[i-1]*nums[i]), nums[i]);
            pos[i] = largest;
            neg[i] = smallest;
            maxcnt = max(largest, maxcnt);
        }
        return maxcnt;
    }
};
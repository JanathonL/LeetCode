334. Increasing Triplet Subsequence
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(m1>=nums[i]) m1=nums[i];
            else if(m2>=nums[i]) m2=nums[i];
            else return true;
        }
        return false;
    }
};
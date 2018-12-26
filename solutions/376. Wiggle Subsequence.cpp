376. Wiggle Subsequence
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> p(n,1);
        vector<int> q(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) q[i]=max(q[i],p[j]+1);
                else if(nums[i]<nums[j]) p[i]=max(p[i],q[j]+1);
            }
        }
        return max(q[n-1],p[n-1]);
    }
};
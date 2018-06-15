// 377. Combination Sum IV
// DP的思路，其实就是一个记忆化搜索，有个trick就是先设置f[i]=-1，然后记录的时候新用一个total去累加，最后f[i]=total， 判断的时候 if (f[i]!=-1) 说明就已经有更新了， return f[i]就好了。
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        vector<int> dp(target+1,-1);
        combinationdp(dp,target,nums);
        return dp[target];
    }
    int combinationdp(vector<int>& dp, int target, vector<int>& nums){
        if(target ==0) return 1;
        if(target <0) return 0;
        if(dp[target]!=-1){
            return dp[target];
        }
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total +=combinationdp(dp,target-nums[i],nums);
        }
        dp[target]=total;
        return dp[target];
        
    }
};
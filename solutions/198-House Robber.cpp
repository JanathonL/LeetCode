// 198. House Robber
// DP time: O(n) Space:O(n)
// d[i]表示偷到第i家的最大钱数
// d[i]= max(d[i-1],d[i-2]+s[i]);

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int dp[10000] = {0};
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<n+1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};
416. Partition Equal Subset Sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        
        int len = nums.size();
        vector<vector<int>> dp(len+1, vector<int>(sum/2 +1, 0));
        dp[0][0]=true;
        for(int i=1;i<len+1;i++){
            for(int j=0;j<sum/2 +1;j++){
                dp[i][j] = dp[i-1][j] || j-nums[i-1]>=0 && dp[i-1][j-nums[i-1]];
                // cout<<"i:"<<i<<"j:"<<j<<" "<<dp[i][j]<<endl;
            }
            if(dp[i][sum/2]==true){
                // cout<<i<<endl;
                return true;
            }
        }
        return false;
        
    }
};
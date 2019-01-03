45. Jump Game II
// refined: greedy
// beat 51.59%
// time: O(N)
// space: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int left = 0;
        int step = 0;
        int right = 0;
        while(left<=right){
            step++;
            int old_right = right;
            for(int i =left;i<=old_right;i++){
                int new_right = i+nums[i];
                if(new_right>=nums.size()-1) return step;
                if(new_right> right) right = new_right; 
            }
            left = old_right+1;
            
        }
        return 0;
    }
};

// timeout DP
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size(),INT_MAX);
        dp[0] = 0;
        for(int i=1;i<nums.size();i++){
            for(int k=0;k<i;k++){
                if(k+nums[k]>=i){
                    dp[i] = min(dp[i], dp[k]+1);
                }
            }
        }
        return dp[nums.size()-1];
    }
};
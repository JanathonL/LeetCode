312. Burst Balloons
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> f(n+2,vector<int>(n+2,0));
        for(int len=1;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                for(int fi=i;fi<=j;fi++){
                    int cost=f[i][fi-1]+f[fi+1][j];
                    cost+= nums[i-1]*nums[fi]*nums[j+1];
                    if(cost>f[i][j]){
                        f[i][j]=cost;
                    }
                }
            }
        }
        return f[1][n];
        
    }
};
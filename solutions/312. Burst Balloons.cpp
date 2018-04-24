// 312. Burst Balloons
// DP: Time: O(n^3)
// f[i][j] 表示nums[i..j] pop之后能收集的最大钱数
// cost = f[i][final-1]+f[final+1][j]    先把两边的nums[I,final-1]  nums[j,final-1] pop 出来。
// cost += nums[i-1]*nums[final]*nums[j+1] 再算当前final pop之后的钱
// f[i][j] = max(cost,f[i][j]);

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
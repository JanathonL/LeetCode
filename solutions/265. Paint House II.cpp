265. Paint House II
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n==0) return 0;
        int k = costs[0].size();
        if(k==0) return 0;
        vector<vector<int>> dp(n,vector<int>(k,INT_MAX));
        int a,b;
        a=b=INT_MAX;
        for(int i=0;i<k;i++){
            dp[0][i]=costs[0][i];
            if(a==INT_MAX){
                a = dp[0][i];
            }
            else if(dp[0][i]<a){
                b=a;
                a=dp[0][i];
            }
            else if(b==INT_MAX){
                b = dp[0][i];
            }
            
            else if(dp[0][i]<b){
                b=dp[0][i];
            }
        }
        for(int i=1;i<n;i++){
            int newa, newb;
            newa=newb=INT_MAX;
            for(int j=0;j<k;j++){
                if(a!=dp[i-1][j]){
                    dp[i][j]=min(dp[i][j], a+costs[i][j]);
                }
                else{
                    dp[i][j]=min(dp[i][j], b+costs[i][j]);
                }
                if(newa==INT_MAX){
                    newa = dp[i][j];
                }
                else if(dp[i][j]<newa){
                    newb=newa;
                    newa=dp[i][j];
                }
                else if(newb==INT_MAX){
                    newb = dp[i][j];
                }
                
                else if(dp[i][j]<newb){
                    newb=dp[i][j];
                }
            }
            a = newa;
            b = newb;
        }
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};
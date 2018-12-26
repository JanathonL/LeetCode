188. Best Time to Buy and Sell Stock IV
class Solution {
public:
    int maxProfit(int k, vector<int>& num) {
        int len = num.size();
        if(len==0) return 0;
        if(k>=len-1){
            int res = 0;
            for(int i=1;i<len;i++){
                if(num[i]-num[i-1]>0){
                    res += num[i]-num[i-1];
                }
            }
            return res;
        }
        vector< vector<vector<int> > > dp;
        dp.resize(len);
        for(int i=0;i<len;i++){
            dp[i].resize(k+1);
            for(int j=0;j<k+1;j++){
                dp[i][j].resize(2);
                for(int x=0;x<2;x++){
                    dp[i][j][x]=0;
                }
            }
        }
        for(int i=0;i<len;i++){
            dp[i][0][1]=-num[0];
            
        }
        for(int j=0;j<k;j++){
            dp[0][j][1]=-num[0];
        }
        for(int i=1;i<len;i++){
            for(int j=0;j<=k;j++){
                if(j!=0)
                    dp[i][j][0]=max(dp[i-1][j-1][1]+num[i],dp[i-1][j][0]);
                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]-num[i]);
                // cout<<i<<" "<<j<<" 0"<<" is:"<<dp[i][j][0]<<" 1"<<" is:"<<dp[i][j][1]<<endl;
            }
        }
        return dp[len-1][k][0];
        
    }
};
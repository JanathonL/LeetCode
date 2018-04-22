class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        unordered_map<int,int> m;
        for(int i=0;i<a.size();i++){
            m[a[i]]=i;
        }
        vector<long> dp(n,1L);
        for(int i=0;i<n;i++){
            int ans = 1;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0&&m.find(a[i]/a[j])!=m.end()){
                    ans = (ans+dp[j]*dp[m[a[i]/a[j]]])%MOD;
                }
            }
            dp[i]=ans;
        }
        int res=0;
        for(int i=0;i<dp.size();i++){
            res = (res+dp[i])%MOD;
        }
        return res%MOD;
        
        
    }
};
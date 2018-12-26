354. Russian Doll Envelopes
class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first) return a.first<b.first;
        else return a.second<b.second;
    }
    int maxEnvelopes(vector<pair<int, int>>& en) {
        sort(en.begin(),en.end(),cmp);
        vector<int> dp(en.size()+1,1);
        int mmax=0;
        dp[0]=0;
        for(int i=0;i<en.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[i+1]>j+1) break;
                if(en[i].first>en[j].first&&en[i].second>en[j].second){
                    dp[i+1]=max(dp[i+1],dp[j+1]+1);
                }
            }
            mmax=max(mmax,dp[i+1]);
        }
        return mmax;
    }
};
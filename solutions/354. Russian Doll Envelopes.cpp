// 354. Russian Doll Envelopes
// 先对数组进行排序，这样直接可以顺序遍历
// DP: O(n^2)  dp[i] 表示第i个元素可以装下多少个信封
// dp[i+1] = max(dp[i+1],dp[j+1]+1)    如果发现dp[j+1]满足条件，就更新，否则dp[i+1]=1;
// 剪枝：if(dp[i+1]>j+1) break;   因为剩余的元素个数都小于dp[i+1]，就算更新也不能变得更大。
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
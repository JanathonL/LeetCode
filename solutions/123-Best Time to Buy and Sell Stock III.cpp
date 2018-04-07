// 123. Best Time to Buy and Sell Stock III
// 这道题思路非常巧妙，我一开始只是正向考虑问题，发现无论怎么定义状态都很麻烦。
// DP思路Time: O(n),  Space: O(n)
// f[i]表示[0,i]单次操作最大利润
// g[i]表示[i,n-1]单次操作最大利润
// f[i] = max(f[i-1],nums[i]-low);
// g[i]=max(g[i+1],high-nums[i]);
// 这里面单次操作体现在了nums[i]-low，而不是f[i-1]+nums[i]-low。要不是过去的那次操作收益大，或者是当前这次。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> f(n,0);
        vector<int> g(n,0);
        int low=prices[0];
        int high=prices[n-1];
        for(int i =1;i<n;i++){
            low = min(low,prices[i]);
            f[i]= max(f[i-1],prices[i]-low);
        }
        for(int i=n-2;i>=0;i--){
            high = max(high,prices[i]);
            g[i] = max(g[i+1],high-prices[i]);
        }
        int profit=0;
        for(int i =0;i<n;i++){
            profit = max(profit,g[i]+f[i]);
        }
        return profit;
    }
};
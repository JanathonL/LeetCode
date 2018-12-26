123. Best Time to Buy and Sell Stock III
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
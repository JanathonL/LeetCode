123. Best Time to Buy and Sell Stock III

// refined
// beat:33.6%
// 3 pass - solution
// time: O(N)
// space: O(N)
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


// refined
// beat: 98%
// time: O(N)
// space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MIN, s1 = 0, b2 = INT_MIN, s2 = 0;
        for (int p : prices) {
            b1 = max(b1, -p);
            s1 = max(s1, b1 + p);
            b2 = max(b2, s1 - p);
            s2 = max(s2, b2 + p);
        }
        return s2;
    }
};
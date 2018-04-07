// 309. Best Time to Buy and Sell Stock with Cooldown
// 这题的关键是要把CD和sell两个操作归为同一个状态，也就是没有股票的状态，
// 这样只需要定义一个sell[i]表示第i天没有股票的时候的最大价值，buy[i]表示第i天持有股票的最大价值。
// sell[i] = max(sell[i-1], buy[i-1]+prices[i])  1. 第二天延续前一天的状态不买股票或者是CD
//                                               2. 把前一天的股票都卖了
// buy[i] = max(buy[i-1], sell[i-2]-prices[i])  1. 第二天继续持有股票不变  
//                                              2. 前一天卖出股票之后，今天再买入股票
// attention: buy[1] = max(-prices[0],-prices[1]).  sell[1] = max(0, prices[1]-prices[0]).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> sell(n,0);
        vector<int> buy(n,0);
        sell[1] = max(0,prices[1]-prices[0]);
        buy[1] = max(-prices[1],-prices[0]);
        for(int i =2;i<n;i++){
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
            buy[i]=max(buy[i-1],sell[i-2]-prices[i]);
            // cout<<"buy:"<<buy[i]<<" sell:"<<sell[i]<<endl;
        }
        return sell[n-1];
        
    }
};

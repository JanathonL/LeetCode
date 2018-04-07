// 188. Best Time to Buy and Sell Stock IV
// DP思路
// 定义两个状态 local[i][j]表示，第i天进行了j次交易，而且第j次交易就是在第i天发生的最大利润。
// global[i][j]表示，第i天可以进行j次交易的最大利润。
// 状态转移方程：
// local[i][j] = max(global[i-1][j-1]+max(diff,0), local[i-1][j]+diff);
//       global[i-1][j-1]+max(diff,0)这个表示过去i-1进行了j-1操作之后的最大值和今天这次操作的值相加，
//       local[i-1][j]+diff表示前一天如果我卖了股票之后又买回来今天才卖掉的收益，这两者比一比。
// global[i][j] = max(global[i-1][j], local[i][j]); 
//      最大值必然是在i-1天进行了至多j次操作的全局最大 和 今天操作之后的局部最大 之中产生。
// attention：
// 1. diff 是price[i]-price[i-1]因为这都是即时的操作，如果它连着操作了很多天就相当于我在第i天卖第j天的股票(i>j).  
// 2. 如果k>prices.size() 直接相当于无限次操作，直接把操作之后收益的股票全加起来。
// 这题的思路好难。
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        if(k>=n){
            return cal(prices);
        }
        vector<vector<int>> local(n,vector<int>(k+1,0));
        vector<vector<int>> global(n,vector<int>(k+1,0));
        int low = prices[0];
        for(int i =1;i<n;i++){
            int diff = prices[i]-prices[i-1];
            for(int j=1;j<=k;j++){
                local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff);
                global[i][j]=max(global[i-1][j],local[i][j]);
            }
        }

        return global[n-1][k];
        
    }
    int cal(vector<int>& prices){
        int sum = 0;
        for(int i =1;i<prices.size();i++){
            sum += max(prices[i]-prices[i-1],0);
        }
        return sum;
    }
};

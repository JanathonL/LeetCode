357. Count Numbers with Unique Digits
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(10,1);
        if(n>10) n=10;
        if(n==0) return 1;
        
        for(int i=1;i<=n;i++){
            int acc = 9;
            for(int j=11-i;j<=9;j++){
                acc*=j;
            }
            dp[i]=dp[i-1]+acc;
        }
        return dp[n];
    }
};
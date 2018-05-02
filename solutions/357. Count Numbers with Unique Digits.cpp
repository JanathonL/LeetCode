// 357. Count Numbers with Unique Digits
// 组合数+DP
// 可以把情况分成两种考虑
// f[n] 表示n时可能的取值
// （1）	最高位为0    f(n-1)种可能
// （2）	最高位不为0    9（不包括0）*9（包括0）*8*…*(11-n)
// 当n>=11的时候  f(n) = f(10)
// f(n) = f(n-1) + 9*9*8*…*(11-n)
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
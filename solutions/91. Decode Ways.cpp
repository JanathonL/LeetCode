/*
7 min
1 wrong
time: O(N)
space: O(N)
*/
class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        if(s.size() == 0){
            return res;
        }
        int n = s.size();
        vector<int> dp(n, 0);
        if(s[0]!='0'){
            dp[0] = 1;
        }
        for(int i=1;i<n;i++){
            if(s[i]!='0'){
                dp[i] += dp[i-1];
            } 
            string num = s.substr(i-1,2);
            if(i==1){
                if(num>="10" && num<="26"){
                    dp[i] += 1;
                }
            } else {
                if(num>="10" && num<="26"){
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n-1];
        
    }
};
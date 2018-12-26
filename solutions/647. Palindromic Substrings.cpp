647. Palindromic Substrings
/*
"aabaa"
n = 5
sum = 9
dp[3][4] = true
dp[2][3] = false
dp[2][4] = false
dp[1][2] = false
dp[1][3] = true
dp[1][4] = false
dp[0][1] = true
dp[0][2] = false
dp[0][3] = false
dp[0][4] = true




*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int sum = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            sum ++;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j] && (i==j-1 || dp[i+1][j-1])){
                    sum++;
                    dp[i][j]=true;
                }
            }
        }
        return sum++;
        
    }
};
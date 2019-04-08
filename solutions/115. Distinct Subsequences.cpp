// 115. Distinct Subsequences
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1,0));
        dp[s.size()][t.size()] = 1;
        for(int i=0;i<s.size();i++){
            dp[i][t.size()] = 1;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j] = dp[i+1][j+1]+dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};


// refined
// beat 54%
// time: O(N^2)
// space: O(N^2)
// dp[i][j] = dp[i-1][j-1] + dp[i-1][j]  
// prev max s[0:i-2] t[0:j-2] nums + prev max s[0:i-2] t[0:j-1]
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<s.size()+1;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<t.size()+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
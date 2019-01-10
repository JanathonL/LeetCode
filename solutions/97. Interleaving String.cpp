97. Interleaving String
// refined
// time:O(m*n)
// space:O(n*m)
// 前s1[0:i-1], s2[0:j-1] 是否能构成s3[0:i+j-1]
class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        for(int i=0;i<=s1.size();i++){  // 注意等号
            for(int j=0;j<=s2.size();j++){ // 注意等号
                if(i==0&&j==0){
                    dp[i][j] = true;
                } else if(i==0){
                    dp[i][j] = dp[i][j-1] && s2[j-1]==s3[i+j-1];
                } else if(j==0){
                    dp[i][j] = dp[i-1][j] && s1[i-1]==s3[i+j-1];
                } else {
                    dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
    
};
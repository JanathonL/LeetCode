// 44. Wildcard Matching
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0] = true;
        for(int j=0;j<p.size();j++){
            dp[0][j+1] = dp[0][j] && p[j] == '*';
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<p.size();j++){
                if(s[i]==p[j] || p[j]=='?'){
                    dp[i+1][j+1] = dp[i][j];
                }
                else if(p[j]=='*'){      
                    dp[i+1][j+1] = dp[i+1][j] || dp[i][j] || dp[i][j+1];   
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

// traverse from the end to beginning DP
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[s.size()][p.size()] = true;
        for(int i=p.size()-1;i>=0;i--){
            if(p[i]!='*') break;
            else dp[s.size()][i]=true;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=p.size()-1;j>=0;j--){
                if(p[j]=='*'){
                    dp[i][j] = dp[i+1][j] || dp[i+1][j+1] || dp[i][j+1];
                }
                if(s[i]==p[j]||p[j]=='?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                // cout<<i<<" "<<j<<endl;
                // cout<<dp[i][j]<<endl;
            }
        }
        return dp[0][0];
        
    }
};



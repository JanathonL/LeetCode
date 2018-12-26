139. Word Break
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[s.size()] = true;
        for(int i=s.size();i>=0;i--){
            for(string w:wordDict){
                if(s.substr(i,w.size())==w){
                    dp[i] = dp[i] || dp[i+w.size()];
                }
            }
        }
        return dp[0];
    }
    
};
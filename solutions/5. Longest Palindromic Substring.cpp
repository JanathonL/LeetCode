5. Longest Palindromic Substring
// beat 28.29%
// time: O(n^2)
// space: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int maxLen = 0;
        int begin;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(j==i) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] =  s[i]==s[j] && (j==i+1||dp[i+1][j-1]) ;
                }
                if(dp[i][j]&&(j-i+1)>maxLen){
                    maxLen = j-i+1;
                    begin = i;
                }
            }
        }                   
        return s.substr(begin, maxLen);
    }
};

// 马拉车算法待命 Manacher's algorithm

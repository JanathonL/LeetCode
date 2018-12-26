516. Longest Palindromic Subsequence
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> mem(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            mem[i][i]=1;
        }
        for(int i=s.size()-2;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                if(i+1==j&& s[i]==s[j]){
                    mem[i][j]=2;
                }
                else if(mem[i+1][j-1] && s[i]==s[j]){
                    mem[i][j]=mem[i+1][j-1]+2;
                }
                else{
                    mem[i][j] = max(mem[i+1][j], mem[i][j-1]);
                }
            }
        }
        return mem[0][s.size()-1];
        
    }
    
};
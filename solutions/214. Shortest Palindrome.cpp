
/*
8 min
memory limit exceed

*/
class Solution {
public:
    /*
        time: O(N^2)
        space: O(N)
    */
    string shortestPalindrome(string s) {
        std::string r = s;
        std::reverse(r.begin(), r.end());

        for (int i = 0; i < s.size(); ++i) {
            if (r.substr(i) == s.substr(0, s.size() - i)) {
                return r.substr(0, i) + s;
            }
        }
        return r + s;
    }
    /*
    time: O(N^2)
    space: O(N^2)
    */
    // string shortestPalindrome(string s) {
    //     if(s.size()==0){
    //         return "";
    //     }
    //     int n = s.size();
    //     vector<vector<bool>> dp(n, vector<bool>(n, false));
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=i;j<n;j++){
    //             if(j==i){
    //                 dp[i][j] = true;
    //             } else {
    //                 if(s[i]==s[j]&& ((i+1==j) || dp[i+1][j-1])){
    //                     dp[i][j] = true;
    //                 }
    //             }
    //         }
    //     }
    //     int max_index = 0;
    //     for(int j=0;j<n;j++){
    //         if(dp[0][j]){
    //             max_index = j;
    //         }
    //     }
    //     string add = s.substr(max_index+1);
    //     reverse(add.begin(), add.end());
    //     return add+s;
    // }
};
115. Distinct Subsequences
DP time: O(n*m)  Space: O(n*m)
f[i][j] 表示 s[0…i-1] 中包含 t[0…j-1]的个数
转移方程
如果 s[i-1]不用的话，f[i][j] = f[i-1][j]，因为不管s[i-1]和t[j-1]相不相等，我不选s[i-1]到我子序列中那么，结果就是和在s[0…i-2]中包含t[0…j-1]一样
if s[i-1]==t[j-1] :  f[i][j] = f[i-1][j] + f[i-1][j-1]  
f[i-1][j]是就算相等也不选s[i-1]的结果数
f[i-1][j-1]是选了s[i-1]然后只需要判断s[0…i-2]中包含t[0…j-2]的个数了。

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> f(n+1,vector<int>(m+1,0));
        f[0][0]=1;
        for(int i =1;i<n+1;i++){
            f[i][0]=1;
            for(int j=1;j<m+1;j++){
                f[i][j]=max(f[i][j],f[i-1][j]);
                if(s[i-1]==t[j-1]){
                    if(j==1) f[i][j]=max(1,f[i][j]);
                    f[i][j]=max(f[i][j],f[i-1][j]+f[i-1][j-1]);
                }
            }
        }
        return f[n][m];
    }
};
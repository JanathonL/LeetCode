// 87. Scramble String
// DP Time: O(n^4),  Space: O(n^3)
// f[n][i][j] 表示从s1[i]为起点和s2[j]为起点的两个长度为n的字符串是否scramble
// f[n][i][j] = f[k][i][j] && f[n-k][i+k][j+k] || f[k][i][j+n-k] && f[n-k][i+k][j]
// 注意初始化f为false
// f[1][i][j] = s1[i]==s2[j];
// 注意边界条件

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int length  = s1.size();
        bool f[length+1][length][length];
        for(int i =0;i<length;i++){
            for(int j =0;j<length;j++){
                f[1][i][j]= s1[i]==s2[j];
                f[0][i][j]= true;
            }
        }
        for(int len = 2;len<length+1;len++){
            for(int i=0;i<=length-len;i++){
                for(int j=0;j<=length-len;j++){
                    f[len][i][j] = false;
                    for(int k=1;k<len&&!f[len][i][j];k++){
                        f[len][i][j]= (f[k][i][j]&&f[len-k][i+k][j+k])||(f[k][i][j+len-k]&&f[len-k][i+k][j]);
                    }
                }
            }
        }
        return f[length][0][0];
    }
};
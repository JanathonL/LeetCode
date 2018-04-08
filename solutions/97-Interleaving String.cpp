// 97. Interleaving String
// DP Time: O(n^2),  Space: O(n^2)
// f[i][j]表示 s1[0…i) 和 s2[0…j) 组合成了s3[0…i+j) 是否是符合条件的
// f[i][j] = s1[i-1] == s3[i+j-1] && f[i-1][j] || s2[j-1] == s3[i+j-1] && f[i][j-1]

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    
        if(s3.length() != s1.length() + s2.length())
            return false;

        bool table[s1.length()+1][s2.length()+1];

        for(int i=0; i<s1.length()+1; i++)
            for(int j=0; j< s2.length()+1; j++){
                if(i==0 && j==0)
                    table[i][j] = true;
                else if(i == 0)
                    table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
                else if(j == 0)
                    table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
                else
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
            }

        return table[s1.length()][s2.length()];
    }
};
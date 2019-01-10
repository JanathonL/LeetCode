87. Scramble String
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

// refined
// pruning
// beat 87%

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        if(s1.size()!=s2.size()) {
            return false;
        }
        // pruning
        int cnt[26] = {0};
        for(int i=0;i<s1.size();i++){
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]!=0) return false;
        }
        for(int i=0;i<s1.size()-1;i++){
            if(isScramble(s1.substr(0,i+1), s2.substr(0,i+1))&&isScramble(s1.substr(i+1),s2.substr(i+1)) || isScramble(s1.substr(0,i+1), s2.substr(s1.size()-i-1))&&isScramble(s1.substr(i+1),s2.substr(0, s1.size()-i-1))) {
                return true;
            }
        }
        return false;
    }
};
482. License Key Formatting

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int cnt = 0;
        for(char c:S){
            if(isalnum(c)){
                cnt++;
            }
        }
        int i = 0;
        while(cnt>0){
            int len = 0;
            if(res==""){
                len = cnt%K==0?K:cnt%K;
            } else {
                len = K;
            }
            cnt -= len;
            while(len>0){
                if(isalnum(S[i])){
                    len--;
                    res += toupper(S[i]);
                }
                i++;
            }
            res += "-";
            
        }
        return res.substr(0, res.size()-1);
    }
};


// refined beat 99%
// time: O(N)
// space: O(1)
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int cnt = 0;
        for(int i=S.size()-1;i>=0;i--){
            if(isalnum(S[i])){
                res += toupper(S[i]);
                cnt ++;
            }
            if(cnt==K){
                res += "-";
                cnt = 0;
            }
        }
        if(res[res.size()-1]=='-'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
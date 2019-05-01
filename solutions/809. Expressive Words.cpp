809. Expressive Words
// refined beat 8%
// time: O(NQ)
// space: O(N)
class Solution {
public:
    void get_key(string& key_s, vector<int>& cnt_s, string s){
        int prev=-1;
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1||s[i]!=s[i+1]){
                key_s+=s[i];
                cnt_s.push_back(i-prev);
                prev = i;
            }
        }
    }
    bool checkOne(string s, string word){
        string key_s, key_w;
        vector<int> cnt_s, cnt_w;
        get_key(key_s,cnt_s, s);
        get_key(key_w,cnt_w, word);
        if(key_s!=key_w) return false;
        for(int i=0;i<cnt_s.size();i++){
            if(cnt_s[i]>=3 && cnt_s[i]>=cnt_w[i] || cnt_s[i]==cnt_w[i]){
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for(string word:words){
            if(checkOne(S,word)){
                res++;
            }
        }
        return res;
    }
};
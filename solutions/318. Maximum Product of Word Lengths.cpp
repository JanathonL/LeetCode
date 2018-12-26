318. Maximum Product of Word Lengths
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> d(words.size(),0);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                d[i] |= (1<<(words[i][j]-'0'));
            }
        }
        int maxcnt = 0;
        for(int i=0;i<words.size();i++){
            for(int j =0;j<words.size();j++){
                if(d[i]&d[j]) continue;
                int len = words[i].size()*words[j].size();
                maxcnt = max(maxcnt,len);
            }
        }
        return maxcnt;
    }
};
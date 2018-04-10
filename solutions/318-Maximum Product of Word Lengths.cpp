// 318. Maximum Product of Word Lengths
// 用int数组d来统计一个单词里各个字母是否出现(0-26位就好了)
// 之后直接d[i]&d[j]判断是否有相同字母
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
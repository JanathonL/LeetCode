// refined
// beat 32.70% (100%)
// time: O(n*k*len)   n is len of string s, k is num of words, len is len of word
// space: O(k*len)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size()==0||s.size()==0) return vector<int>();
        vector<int> result;
        unordered_map<string,int> expected;
        
        for(int i=0;i<words.size();i++){
            expected[words[i]]++;
        }
        int appear = 0, n = s.size(), num = words.size(), len = words[0].size();
        int i,j;
        for(i = 0;i<n-num*len+1;i++){
            unordered_map<string,int> appeared;
            for(j=0;j<num;j++){
                string tmp = s.substr(i+j*len,len);
                if(expected[tmp]>0){
                    appeared[tmp]++;
                    if(appeared[tmp]>expected[tmp]){
                        break;
                    }
                } else {
                    break;
                }
            }
            if(j==num) result.push_back(i);
        }
        return result;
    }
};
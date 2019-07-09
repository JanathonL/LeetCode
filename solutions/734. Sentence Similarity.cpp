734. Sentence Similarity
/* 
time: O(N)
space: O(NM)
corner case
1. pairs.size() != words.size() 
2. same word in a pair is similar to diff words
*/
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size()!=words2.size()){
            return false;
        }
        unordered_map<string, unordered_set<string>> dict1;
        for(auto pair:pairs){
            dict1[pair[0]].insert(pair[1]);
        }
        for(int i=0;i<words1.size();i++){
            if(words1[i]==words2[i] || dict1.count(words1[i]) && dict1[words1[i]].count(words2[i]) || dict1.count(words2[i]) && dict1[words2[i]].count(words1[i])){
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
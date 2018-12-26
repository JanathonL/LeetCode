737. Sentence Similarity II
class Solution {
public:
    unordered_map<string, string> parent;
    string find(string s){
        if( parent[s] == s){
           return s;
        }
        else{
            parent[s] = find(parent[s]);
            return parent[s];
        }
    }
    void connected(string str1, string str2){
        str1 = find(str1);
        str2 = find(str2);
        if(str1==str2) return ;
        if(str1>str2){
            parent[str2] = str1;
        }
        else{
            parent[str1] = str2;
        }
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size()) return false;
        if(words1.size() == words2.size() && words1.size() == 0) return true;
        for(int i=0;i<pairs.size();i++){
            parent[pairs[i].first] = pairs[i].first;
            parent[pairs[i].second] = pairs[i].second;
        }
        for(int i=0;i<pairs.size();i++){
            connected(pairs[i].first, pairs[i].second);
        }
        
        for(int i=0;i<words1.size();i++){
            if(words1[i]!=words2[i] && find(words1[i]) != find(words2[i])){
                return false;
            }
        }
        return true;
    }
};
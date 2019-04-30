833. Find And Replace in String
// refined 97%
// time: O(N*Q)
// space: O(N)
class Solution {
public:
    /*
     bind the indexes with sources and targets using hash map
     iterate the whole string from start to the end
     if index in the hashmap and str begin at index is matched with sources{
        put the target to res
        skip word
     } else {
        put c to res
     }
    */
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets){
        unordered_map<int, pair<string,string>> dict;
        for(int i=0;i<indexes.size();i++){
            dict[indexes[i]] = {sources[i], targets[i]};   
        }
        string res;
        for(int i=0;i<S.size();i++){
            if(dict.count(i) && dict[i].first==S.substr(i,dict[i].first.size())){
                res += dict[i].second;
                i += dict[i].first.size()-1;
            } else {
                res += S[i];
            }
        }
        return res;
    }
};
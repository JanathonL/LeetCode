49. Group Anagrams
/*
hash map <sorted string, vector<string>>
bug free!!
5 min
time: O(N*klogk)  k is the len of string


*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size()==0){
            return res;
        }
        unordered_map<string, vector<string>> dict;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            dict[tmp].push_back(strs[i]);
        }
        for(auto item:dict){
            res.push_back(item.second);
        }
        return res;
    }
};
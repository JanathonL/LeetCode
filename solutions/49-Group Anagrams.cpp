// 49. Group Anagrams
// 直接两个map映射一下
// 一个是odered[string] -> sorted_string
// 另一个是 res[sorted_string] -> vector<string>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,string> ordered;
        unordered_map<string,vector<string>> stor;
        vector<string> temp(strs);
        for(auto s:temp){
            string old = s;
            sort(s.begin(),s.end());
            ordered[old]=s;
            stor[s]=vector<string>();
        }
        for(auto s:strs){
            stor[ ordered[s] ].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it:stor){
            res.push_back(it.second);
        }
        return res;
    }
};
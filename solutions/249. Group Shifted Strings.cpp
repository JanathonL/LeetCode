// 249. Group Shifted Strings
// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

// Example:

// Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
// Output: 
// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
class Solution {
public:
    string get_patt(string str){
        if(str=="") return "";
        int dist = str[0]-'a';
        for(int i=0;i<str.size();i++){
            // check if the result is still an alphabet 
            int d = str[i]-'a';
            d -= dist;
            if(d<0) d+= 26;
            str[i] = d+'a';
        }
        return str;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for(int i=0;i<strings.size();i++){
            string key = get_patt(strings[i]);
            m[key].push_back(strings[i]);
        }
        vector<vector<string>> result;
        for(auto item:m){
            vector<string> temp = item.second;
            sort(temp.begin(),temp.end());
            result.push_back(temp);
        }
        return result;
    }
};
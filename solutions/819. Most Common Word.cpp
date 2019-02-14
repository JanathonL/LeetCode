819. Most Common Word
// refined
// beat: 100%
// time: O(N)
// space: O(N)
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        string temp;
        unordered_map<string, int> dict;
        int i = 0;
        while(i<paragraph.size()){
            string temp = "";
            while(i<paragraph.size()&&isalpha(paragraph[i])){
                temp += tolower(paragraph[i]);
                i++;
            }
            dict[temp]++;
            while(i<paragraph.size()&&!isalpha(paragraph[i])){
                i++;
            }
        }
        int max_cnt = 0;
        string res;
        for(auto item:dict){
            if(item.second>max_cnt && !ban.count(item.first)){
                max_cnt = item.second;
                res = item.first;
            }
        }
        return res;
    }
};
/*
start from begin
if cur == end {
    add to res
}
change one word a time -> find in dict && not visited -> if find -> dfs
26 min 
TLE
time: O(26^n) n is the num of word in wordList
*/
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> dict;
//         for(string word:wordList){
//             dict.insert(word);
//         }
//         vector<vector<string>> res;
//         // check the end not in the dict
//         if(!dict.count(endWord)){
//             return res;
//         }
//         // check the length of begin and end
//         if(beginWord.size()!=endWord.size()){
//             return res;
//         }
//         vector<string> cur;
//         cur.push_back(beginWord);
//         dfs(beginWord, endWord, dict, cur, res);
//         return res;
//     }
//     void dfs(string start, string end, unordered_set<string> dict, vector<string> cur, vector<vector<string>>& res){
//         // cout<<start<<" "<<end<<endl;
//         if(start==end){
//             if(res.size()==0 || cur.size()==res.back().size()){
//                 res.push_back(cur);
//             } else if(cur.size()<res.back().size()){
//                 while(res.size()>0){
//                     res.pop_back();
//                 }
//                 res.push_back(cur);
//             }
//         }
//         if(res.size()>0 && res.back().size()<=cur.size()){
//             return;
//         }
//         for(int i=0;i<start.size();i++){
//             for(int j=0;j<26;j++){
//                 int c = start[i];
//                 if(c==j+'a') continue;
//                 start[i] = j+'a';
//                 // cout<<start<<endl;
//                 if(dict.count(start)){
//                     // visited
//                     dict.erase(start);
//                     cur.push_back(start);
//                     dfs(start, end, dict, cur, res);
//                     // restore
//                     cur.pop_back();
//                     dict.insert(start);
//                 }
//                 // restore
//                 start[i] = c;
//             }
//         }
//     }
// };

// Author: Huahua
// Running time: 39 ms (better than 93.74%)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans;
        
        int l = beginWord.length();
        
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        unordered_map<string, vector<string>> children;
 
        bool found = false;
        bool backward = false;
        
        while (!q1.empty() && !q2.empty() && !found) {            
            // Always expend the smaller queue first
            if (q1.size() > q2.size()) {
                std::swap(q1, q2);
                backward = !backward;
            }
            
            for (const string& w : q1)
                dict.erase(w);
            for (const string& w : q2)
                dict.erase(w);
                        
            unordered_set<string> q;
            
            for (const string& word : q1) {
                string curr = word;
                for (int i = 0; i < l; i++) {
                    char ch = curr[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        curr[i] = j;
                        
                        const string* parent = &word;
                        const string* child = &curr;
                        
                        if (backward)
                            std::swap(parent, child);
                        
                        if (q2.count(curr)) {
                            found = true;
                            children[*parent].push_back(*child);
                        } else if (dict.count(curr) && !found) {
                            q.insert(curr);
                            children[*parent].push_back(*child);
                        }
                    }
                    curr[i] = ch;
                }
            }
            
            std::swap(q, q1);
        }
        
        if (found) {
            vector<string> path{beginWord};
            getPaths(beginWord, endWord, children, path, ans);
        }
        
        return ans;
    }
private:
    void getPaths(const string& word, 
                  const string& endWord,                   
                  const unordered_map<string, vector<string>>& children, 
                  vector<string>& path, 
                  vector<vector<string>>& ans) {        
        if (word == endWord) {
            ans.push_back(path);
            return;
        }
        
        const auto it = children.find(word);
        if (it == children.cend()) return;
        
        for (const string& child : it->second) {
            path.push_back(child);
            getPaths(child, endWord, children, path, ans);
            path.pop_back();
        }
    }
};
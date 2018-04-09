// 139. Word Break

// DFS会超时（T O(2^n)）
// DP（T O(n^2)）定义一个f[i] = findany(f[j], s[j..i-1] in dict)
// f[i]表示s[0...i-1]是否是符合条件

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> f(n+1,false);
        f[0]=true;
        for(int i =1;i<n+1;i++){
            for(int j =0;j<i;j++){
                auto it = find(wordDict.begin(),wordDict.end(),s.substr(j,i-j));
                if(f[j]&&it!=wordDict.end()){
                    f[i]=true;
                    break;
                }
            }
        }
        return f[n];
    }
    
};
// DFS Time O(2^n) TLE
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
        
//         return dfs(s,0,wordDict);
//     }
//     bool dfs(string s, int start, vector<string> wordDict){
//         if(start==s.size()){
//             return true;
//         }
//         if(wordDict.size()==0) return false;
//         if(start==s.size()) return false;
//         for(int i=start;i<s.size();i++){
//             string tmp = s.substr(start,i-start+1);
//             // cout<<tmp<<endl;
//             auto it = find(wordDict.begin(),wordDict.end(),tmp);
//             if(it!=wordDict.end()){
//                 bool res = dfs(s,i+1,wordDict);
//                 if(res) return true;
//             }
//         }
//         return false;
//     }
// };
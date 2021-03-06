// 140. Word Break II
// 在上一题的基础上保留一个prev[i][j]判断s[i...j-1]是否在字符串中，然后DFS遍历，
// 有一个问题，我从前往后搜索在一个case会超时，但是在从后往前搜索就没事。
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> f(n+1,false);
        vector<vector<bool>> prev(n+1,vector<bool>(n+1,false));
        f[0]=true;
        
        for(int i=1;i<n+1;i++){
            for (int j = i - 1; j >= 0; --j) {
                auto it = find(wordDict.begin(),wordDict.end(),s.substr(j,i-j));
                if(f[j]&&it!=wordDict.end()){
                    f[i] = true;
                    prev[i][j] = true;
                }
            }
        }
        vector<string> result,path;
        gen_path(s,prev,s.length(),path,result);
        return result;
        
    }
    void gen_path(const string &s, const vector<vector<bool> > &prev,
            int cur, vector<string> &path, vector<string> &result) {
        if (cur == 0) {
            string tmp;
            for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
                tmp += *iter + " ";
            tmp.erase(tmp.end() - 1);
            result.push_back(tmp);
        }
        for (size_t i = 0; i < s.size(); ++i) {
            if (prev[cur][i]) {
                path.push_back(s.substr(i, cur - i));
                gen_path(s, prev, i, path, result);
                path.pop_back();
            }
        }
    }
};
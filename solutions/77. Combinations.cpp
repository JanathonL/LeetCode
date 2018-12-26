77. Combinations
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n==0||k==0) return result;
        vector<int> path;
        dfs(result,path,0,0,n,k);
        return result;
    }
    void dfs(vector<vector<int>>& result, vector<int> path, int start, int cur, int n, int k){
        if(cur==k){
            result.push_back(path);
            return;
        }
        for(int i = start+1;i<=n;i++){
            path.push_back(i);
            dfs(result,path,i,cur+1,n,k);
            path.pop_back();
        }
    }
};
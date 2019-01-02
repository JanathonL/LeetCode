40. Combination Sum II
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(candidates,result,target,0,path,0);
        return result;
    }
    void dfs(vector<int>& candidates, vector<vector<int>>& result, int target, int sum, vector<int> path, int start){
        if(sum>target){
            return ;
        }
        if(sum==target&&path.size()>0){
            // sort(path.begin(),path.end());
            // if(find(result.begin(),result.end(),path)==result.end())
            result.push_back(path);
            return;
        }
        int n = candidates.size();
        int previous = -1;
        for(int i=start;i<n;i++){
            if (previous == candidates[i]) continue;
            if(sum+candidates[i]>target) break;
            previous = candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates,result,target,sum+candidates[i],path,i+1);
            path.pop_back();
        }
    }
};


// refined
// 45.37%
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0) return vector<vector<int>>();
        vector<vector<int>> res;
        vector<bool> visited(candidates.size(),false);
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, res, visited, 0, vector<int>());
        return res;
    }
    void backtrack(vector<int> candidates, int target, vector<vector<int>> &res,
                   vector<bool> visited, int start, vector<int> cur){
        if(target==0){
            res.push_back(cur);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>0&&candidates[i-1]==candidates[i]&&!visited[i-1]){  // remove duplicate
                // cout<<i<<endl;
                continue;
            }
            if(target>=candidates[i]){
                visited[i] = true;
                cur.push_back(candidates[i]);
                backtrack(candidates, target-candidates[i], res, visited, i+1, cur);
                visited[i] = false;
                cur.pop_back();
            } else {
                break;
            }
        }
    }
    
};
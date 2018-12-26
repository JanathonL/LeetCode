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
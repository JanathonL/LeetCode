216. Combination Sum III
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> candidates{1,2,3,4,5,6,7,8,9};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(candidates,result,target,0,path,0,0,k);
        return result;
    }
    void dfs(vector<int>& candidates, vector<vector<int>>& result, int target, int sum, vector<int> path, int start, int cnt,int k){
        if(sum>target){
            return ;
        }
        if(cnt>k) return ;
        if(sum==target&&path.size()>0&&cnt==k){
            // sort(path.begin(),path.end());
            // if(find(result.begin(),result.end(),path)==result.end())
            result.push_back(path);
            return;
        }
        int n = candidates.size();
        int pre = -1;
        for(int i=start;i<n;i++){
            if(pre==candidates[i]) continue;
            if(sum+candidates[i]>target) break;
            pre = candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates,result,target,sum+candidates[i],path,i+1,cnt+1,k);
            path.pop_back();
        }
    }
};
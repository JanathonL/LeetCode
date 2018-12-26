39. Combination Sum
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        // perform backtracking
        int pos = 0;
        int sum = 0;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, pos, sum, cur, res);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, int pos, int sum, vector<int> cur, vector<vector<int>>& res){
        if(sum==target){
            res.push_back(cur);
            return;
        }
        if(pos==candidates.size()){
            return;
        }
        for(int i=pos;i<candidates.size();i++){
            if(sum+candidates[i] <= target){
                cur.push_back(candidates[i]);
                backtrack(candidates, target, i, sum+candidates[i], cur, res);
                cur.pop_back();
            } else{
                break;
            }
        }
    }
};
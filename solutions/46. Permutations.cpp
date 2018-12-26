// 46. Permutations
// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        unordered_set<int> visited;
        if(nums.size()==0) return res;
        dfs(nums, res, cur, visited);
        return res;
    }
    void dfs(vector<int> nums, vector<vector<int>>& res, vector<int> cur, unordered_set<int> visited){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited.count(nums[i])) continue;
            visited.insert(nums[i]);
            cur.push_back(nums[i]);
            dfs(nums,res,cur,visited);
            visited.erase(nums[i]);
            cur.pop_back();
        }
    }
    
    
};
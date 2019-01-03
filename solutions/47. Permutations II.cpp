47. Permutations II
/*
backtrack
pick ith item add to res, mark ith item visited
for the duplicate, use a hash set when backtracking
before pick ith item, check if ith item exists in hash map first

10 min 
bug free!!
time: O(n!)
space: O(n)
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        if(nums.size()==0){
            return res;
        }
        vector<int> cur;
        vector<bool> visited(nums.size(),false);
        backtrack(nums, res, cur, visited);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int> cur, vector<bool>& visited){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }
        int n = nums.size();
        unordered_set<int> cache;
        for(int i=0;i<n;i++){
            if(visited[i] || cache.count(nums[i])){
                continue;
            }
            cache.insert(nums[i]);
            cur.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, res, cur, visited);
            visited[i] = false;
            cur.pop_back();
        }
    }
};


// refined
// beat 46.08%
// time: O(n!)
// space: O(n)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        if(nums.size()==0) return res;
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(), nums.end());
        dfs(nums, res, cur, visited);
        return res;
    }
    void dfs(vector<int> nums, vector<vector<int>>& res, vector<int> cur, vector<bool> visited){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0&& nums[i-1]==nums[i] && !visited[i-1]) continue;
            if(visited[i]) continue;
            cur.push_back(nums[i]);
            visited[i] = true;
            dfs(nums,res,cur,visited);
            visited[i] = false;
            cur.pop_back();
        }
    }
};


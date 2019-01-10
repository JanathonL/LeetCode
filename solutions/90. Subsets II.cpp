90. Subsets II
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        int n = nums.size();
        map< vector<int> ,int> m;
        for(int i=0;i<1<<n;i++){
            for(int j=0;j<n;j++){
                if(i& 1<<j) {
                    path.push_back(nums[j]);
                }
            }
            sort(path.begin(),path.end());
            if(m.find(path)==m.end()){
                m[path]=0;
                result.push_back(path);
            }
            
            
            path.clear();
        }
        return result;
    }
};


// refined
// beats:68%
// time: O(2^n)
// space: O(n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(),nums.end());  // make sure every duplicate num stay together
        dfs(res, nums, cur, 0, used);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int>& nums, vector<int> cur, int start, vector<bool>& used){
        res.push_back(cur);
        for(int i=start;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]&&!used[i-1]){  // remove duplicate
                continue;
            }
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(res, nums, cur, i+1, used);
            cur.pop_back();
            used[i] = false;
        }
    }
};


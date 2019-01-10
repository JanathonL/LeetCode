78. Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // visit.resize(nums.size());
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums,result,path,0);
        // result.push_back(vector<int>());
        return result;
    }
    void dfs(vector<int> nums, vector<vector<int>>& result,vector<int> path, int step){
        if(step==nums.size()){
            result.push_back(path);
            return;
        }
        //not choose
        dfs(nums,result,path,step+1);
        //choose
        path.push_back(nums[step]);
        dfs(nums,result,path,step+1);
        path.pop_back();
        
    }
    
};
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         visit.resize(nums.size());
//         vector<vector<int>> result;
//         for(int i =0;i<visit.size();i++){
//             visit[i]=0;
//         }
//         for(int i =0;i<visit.size();i++){
//             dfs(nums,result,i);
//         }
//         result.push_back(vector<int>());
//         return result;
//     }
//     void dfs(vector<int> nums, vector<vector<int>>& result,int i){

//         visit[i]=1;
//         tmp.push_back(nums[i]);


//         for(int k = i+1;k<nums.size();k++){
//             if(visit[k]==0){
//                 dfs(nums,result,k);
//                 visit[k]=0;
//             }
//         }
//         result.push_back(tmp);
//         tmp.pop_back();
//     }
// private:
//     vector<int> visit;
//     vector<int> tmp;
// };


// refined
// beat 100%
// time: O(2^n)
// space: O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, nums, cur, 0);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int>& nums, vector<int> cur, int start){
        res.push_back(cur);
        for(int i=start;i<nums.size();i++){
            cur.push_back(nums[i]);
            dfs(res, nums, cur, i+1);
            cur.pop_back();
        }
    }
};
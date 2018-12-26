// 698. Partition to K Equal Sum Subsets
// Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

// Example 1:
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
// Note:

// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto item:nums){
            sum+=item;
        }
        vector<bool> visited(nums.size(),false);
        if(sum%k!=0){ 
            return false;
        }
        int cur = 0;
        unordered_map<int, bool> mem;
        // sort(nums.begin(),nums.end());
        // cout<<sum/k<<endl;
        return dfs(nums,k,visited,0,cur,sum/k,mem);
    }
    bool dfs(vector<int> nums, int k, vector<bool> visited, int cur_cnt, int cur, int sum, unordered_map<int, bool>& mem){
        int state = getstate(visited);
        if(mem.find(state)!=mem.end()) return mem[state];
        if(cur_cnt==sum){
            if(cur+1==k){
                mem[state]  = true;
                return true;
            }
            bool res = dfs(nums, k, visited, 0, cur+1, sum, mem);
            mem[state] = res;
            return res;
        }
        bool res = false;
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                if(cur_cnt+nums[i]>sum) {
                    visited[i]=false;
                    continue;
                }
                res = dfs(nums,k,visited,cur_cnt+nums[i], cur, sum,mem);

                if(res) {
                    mem[state] = true;
                    return true;
                }
                visited[i]=false;
            }
        }
        mem[state] = res;
        return res;
    }
    int getstate(vector<bool> visited){
        int state=0;
        for(int i=0;i<visited.size();i++){
            state |= visited[i]<<i;
        }
        return state;
    }
};